#include <bits/stdc++.h>
constexpr int A = 102;

int n, m, b[A];

struct Vec2D {
	int x, y, d;
	auto next() const -> Vec2D {
		if (y == 1 && d == -1) return { x + 1, 1, -d };
		if (y == n && d == 1) return { x + 1, n, -d };
		return { x, y + d, d };
	}
};

auto main() -> int {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1, tot = n * m, a; i <= tot; i++) {
		std::cin >> a, b[a] = i;
	}
	Vec2D set{ 1, 1, 1 };
	for (int i = 100; i; i--) {
		if (b[i] == 1) break;
		else if (b[i]) set = set.next();
	}
	std::cout << set.x << ' ' << set.y << '\n';
}
