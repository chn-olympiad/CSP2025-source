#include <iostream>
#include <string>

std::string str;
int times[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> str;

	for (const auto& ch : str) {
		if (isdigit(ch)) {
			++times[ch - '0'];
		}
	}

	for (int i = 9; i >= 0; --i) {
		for (int j = times[i]; j--; ) {
			std::cout << i;
		}
	}
	std::cout << std::endl;

	return 0;
}
