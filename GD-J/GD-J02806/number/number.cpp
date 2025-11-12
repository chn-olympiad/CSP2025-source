#include <iostream>
#include <cstdio> 
#include <string>
#include <vector>
#include <algorithm>

bool isDigit(char c) {
	return c <= '9' && c >= '0';
}

int main(void) {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::string s;
	std::cin >> s;
	std::vector<char> num;
	for (int i = 0; i != s.size(); ++i) {
		if (isDigit(s[i])) {
			num.push_back(s[i]);
		}
	}
	std::sort(num.begin(), num.end());
	if (num[num.size() - 1] == '0') {
		std::cout << "0\n";
		return 0;
	}
	for (int i = num.size() - 1; i >= 0; --i) {
		printf("%c", num[i]);
	}
	std::cout << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
