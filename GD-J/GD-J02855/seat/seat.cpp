#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int, int);
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[105] {};
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int little_R = a[0];
	sort(a, a + n * m, cmp);
	int dir = 0;
	int x = 1, y = 1;
	for (int i = 0; i < n * m; i++) {
		if (a[i] == little_R) {
			cout << y << ' ' << x;
			break;
		}
		switch (dir) {
			case 0:
				if (x == n) {
					dir = 1;
					y++;
					break;
				}
				x++;
				break;
			case 1:
				if (x == 1) {
					dir = 0;
					y++;
					break;
				}
				x--;
				break;
		}
	}
	return 0;
}
bool cmp(int a, int b) {
	return a > b;
}
// 100 pts
