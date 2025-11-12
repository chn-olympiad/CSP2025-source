#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	std::string s;
	std::cin >> s;

	std::vector<char> all;
	for (char x : s)
	{
		if (x >= '0' && x <= '9')
		{
			all.push_back(x);
		}
	}

	std::sort(all.begin(), all.end(), [](const int& x, const int& y) -> bool
	{
		return x > y;
	});

	for (char x : all)
	{
		std::cout << x;
	}
	std::cout << std::endl;

	return 0;
}
