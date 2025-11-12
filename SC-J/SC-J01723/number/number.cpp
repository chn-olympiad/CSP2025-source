#include <iostream>
#include <cstdio>
#include <string>
int times[10];
int main() {
	std::freopen("number.in", "r", stdin);
	std::freopen("number.out", "w", stdout);
	
	std::string data;
	std::cin >> data;
	for (const auto& c : data) {
		if (c >= '0' && c <= '9') times[c^48]++;
	}
	for (int num = 9; num >= 0; num--) {
		while (times[num] > 0) {
			std::cout << num;
			times[num]--;
		}
	}
	
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}