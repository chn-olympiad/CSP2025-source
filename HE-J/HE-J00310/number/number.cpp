#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::string str;
	
	std::cin >> str;

	std::sort(str.begin(), str.end());
	
	for (int i = str.length() - 1; i >= 0; i--)
		if (isdigit(str[i]))
			std::cout << str[i];
	return 0;
}
