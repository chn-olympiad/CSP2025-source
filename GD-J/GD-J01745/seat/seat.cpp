#include <iostream>
#include <algorithm>
#include <cmath>

int n, m; // 行数, 列数
int self_score; // 自己的分数 
int a[1005];

bool cmp(int a, int b) {
	return a > b;
}

std::pair<int, int> get_pos(int num) {
	int x = 1, y = 1;
	for (int i = 1; i < num; i++) {
//		std::cout << x << ' ' << y << std::endl; 
		if (x % 2) {
			if (y == n) {
				x++; 
			} else {
				y++;
			}
		} else {
			if (y == 1) {
				x++;
			} else {
				y--;
			}
		}
	}
	return { x, y };
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		std::cin >> a[i];
	}
	self_score = a[1];
	std::sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
//		std::cout << "Debug: a[" << i << "] = " << a[i] << ',';
		if (a[i] == self_score) {
			std::pair<int, int> ans = get_pos(i);
			std::cout << ans.first << ' ' << ans.second;
			return 0;
		}
	}
	return 0;
} 
