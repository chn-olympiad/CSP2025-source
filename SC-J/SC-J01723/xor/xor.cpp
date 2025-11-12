#include <iostream>
#include <cstdio>
#include <vector>
int n, k;
std::vector<int> a;
int main() {
	std::freopen("xor.in", "r", stdin);
	std::freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	for (int i = 0;i < n;i++) {
		int num;
		std::cin >> num;
		a.emplace_back(num);
	}
	if (k == 1) {
		int counter = 0;
		for (int i = 0;i < a.size();i++) {
			if (a[i] == 1) counter++; 
		}
		std::cout << counter;
	} else if (k == 0) {
		int counter = 0;
		for (int i = 0;i < a.size();i++) {
			if (a[i] == 0) counter++; 
			if (i + 1 < a.size() && a[i] == 1 && a[i + 1] == 1) {
				counter++;
				i++;
			}
		}
		std::cout << counter;
	} else {
		int res = 0, counter = 0;
		for (int i = 0;i < a.size();i++) {
			int tmp_counter = 0;
			for (int j = i;j < a.size();j++) {
				res ^= a[i];
				if (res == k) {
					res = 0, tmp_counter++;
				}
			}
			counter = std::max(tmp_counter, counter);
		}
		std::cout << counter;
	}
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}