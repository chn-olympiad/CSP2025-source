#include <iostream>

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m, val, a, index = 1;
	std::cin >> n >> m >> val;
	int sz = n * m;
	for (int i = 1; i < sz; i++) {
		std::cin >> a;
		if (a > val) { index++; }
	}
	// std::cout << index << '\n';
	int x, y;
	x = (index - 1) / n + 1;
	if (x % 2 == 1) {
		y = (index - 1) % n + 1;
	} else {
		y = n - index % n + 1;
	}
	std::cout << x << ' ' << y << '\n';
}
