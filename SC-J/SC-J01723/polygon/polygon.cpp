#include <iostream>
#include <cstdio>
#include <vector>

std::vector<int> sticks;
long long power(int index) {
	long long ans = 1;
	while (index > 0) {
		ans *= 2;
		index--;
	}
	return ans;
}
int main() {
	std::freopen("polygon.in", "r", stdin);
	std::freopen("polygon.out", "w", stdout);
	int n;
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		std::cin >> a;
		sticks.emplace_back(a);
	}
	std::cout << (power(n) - 4) % 998244353;
	
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}