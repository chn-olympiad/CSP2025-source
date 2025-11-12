#include <iostream>
#include <string>
#include <algorithm>

bool cmp(char a, char b) {
	return a > b;
} 

std::string str;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout) ;
	char x;
	while (std::cin >> x) {
		if ('0' <= x && x <= '9') {
			str += x;
		}
	}
	sort(str.begin(), str.end(), cmp);
	std::cout << str;
	return 0;
}
