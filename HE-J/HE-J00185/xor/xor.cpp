#include <iostream>
int n, k, cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	long a[n], acc[n];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	acc[0] = a[0];
	for (int i = 1; i < n; ++i)
		acc[i] = acc[i - 1] ^ a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if ((acc[j - 1] ^ acc[i]) == k)
				++cnt;
		}
	}
	std::cout << cnt;
}
