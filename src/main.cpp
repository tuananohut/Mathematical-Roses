#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

const float PI = acos(0.0f) * 2;

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(1580, 1000), "Mathematical Roses", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	sf::View view = window.getDefaultView();
	view.setCenter(0.0f, 0.0f);
	window.setView(view);

	float nN = 300.0f;
	float nD = 400.0f;

	sf::RectangleShape nSlider(sf::Vector2f(350.0f, 20.0f));
	nSlider.setOrigin(sf::Vector2f(175.0f, 10.0f));
	nSlider.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - 270.0f));
	nSlider.setFillColor(sf::Color::White);

	sf::RectangleShape nSliderR(sf::Vector2f(350.0f - nN, 20.0f));
	nSliderR.setOrigin(sf::Vector2f(175.0f, 10.0f));
	nSliderR.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - 270.0f));
	nSliderR.setFillColor(sf::Color::Red);

	sf::RectangleShape dSlider(sf::Vector2f(450.0f, 20.0f));
	dSlider.setOrigin(sf::Vector2f(225.0f, 10.0f));
	dSlider.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - 230.0f));
	dSlider.setFillColor(sf::Color::White);

	sf::RectangleShape dSliderR(sf::Vector2f(450.0f - nD, 20.0f));
	dSliderR.setOrigin(sf::Vector2f(225.0f, 10.0f));
	dSliderR.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - 230.0f));
	dSliderR.setFillColor(sf::Color::Blue);

	sf::Vertex point;

	sf::Font font;

	if(!font.loadFromFile("../../Mathematical Roses/Mathematical Roses/OpenSans-Bold.ttf"))
	{
		std::cout << "!";
	}

	sf::Text nText;
	sf::Text dText;

	nText.setCharacterSize(20.0f);
	nText.setFillColor(sf::Color::Black);
	nText.setFont(font);
	nText.setOrigin(sf::Vector2f(0.0f, 0.0f));
	nText.setPosition(sf::Vector2f(view.getCenter().x - 50.0f, view.getCenter().y - 285.0f));

	dText.setCharacterSize(20.0f);
	dText.setFillColor(sf::Color::Black);
	dText.setFont(font);
	dText.setOrigin(sf::Vector2f(0.0f, 0.0f));
	dText.setPosition(sf::Vector2f(view.getCenter().x - 50.0f, view.getCenter().y - 241.0f));

	std::string nString = "n value: " + std::to_string(static_cast<int>(nN / 300.0f));
	std::string dString = "d value: " + std::to_string(static_cast<int>(nD / 400.0f));

	nText.setString(nString);
	dText.setString(dString);
	
	float n = 1.0f;
	float d = 1.0f;
	float k = n / d;

	point.color = sf::Color::White;
	bool nKeyPressed = false;
	bool dKeyPressed = false;

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && !nKeyPressed) 
			{
				nKeyPressed = true;

				if (nN > 0.0f) 
				{
					nN -= 50.0f;
				}
				else {
					nN = 300.0f;
				}
				nSliderR.setSize(sf::Vector2f(350.0f - nN, 20.0f));

				if (n < 7.0f) {
					n += 1.0f;
				}
				else 
				{
					n = 1.0f;
				}

				k = n / d;

				std::string nString = "n value: " + std::to_string(static_cast<int>(n));
				nText.setString(nString);
			}

			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::N)) 
			{
				nKeyPressed = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !dKeyPressed) 
			{
				dKeyPressed = true;

				if (nD > 0.0f) {
					nD -= 50.0f;
				}
				else {
					nD = 400.0f;
				}

				dSliderR.setSize(sf::Vector2f(450.0f - nD, 20.0f));

				if (d < 9.0f) 
				{
					d += 1.0f;
				}
				else 
				{
					d = 1.0f;
				}

				k = n / d;

				std::string dString = "d value: " + std::to_string(static_cast<int>(d));
				dText.setString(dString);
			}

			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
			{
				dKeyPressed = false;
			}
		}
		
		window.clear(sf::Color::Black);

		for(float a = 0.0f; a <  2 * PI * 20; a += 0.01f)
		{
			float r = 200.0f * cos(k * a);
			float x = r * cos(a);
			float y = r * sin(a);
			point.position = sf::Vector2f(x, y);

			window.draw(&point, 2, sf::Points);
		}	
		window.draw(nSlider);
		window.draw(nSliderR);
		window.draw(dSlider);
		window.draw(dSliderR);
		window.draw(nText);
		window.draw(dText);

		window.display();
	}
	
	return 0;
}
