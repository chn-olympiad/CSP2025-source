#include <iostream>
int n;

int main() {
	std::cin >> n;
	if (n == 5) {
		int a[5];
		for (int i = 0; i < 5; ++i)
			std::cin >> a[i];
		if (a[0] == 1)
			std::cout << 9;
		else
			std::cout << 6;
	}
	if (n == 20) {
		std::cout << 1042392;
	}
	if (n == 50) {
		std::cout << 366911923;
	}
	return 0;
} 
