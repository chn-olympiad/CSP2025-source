#include <bits/stdc++.h>
#define N 20
using namespace std;
int n, m, x, y, rk;
int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	cin >> n >> m >> x;
	for (int i = 2; i <= n * m; i++) {
		cin >> y;
		if (y > x) rk++;
	}
	x = y = 1;
	int pd = 1;
	while (rk--) {
		x += pd;
		if (x > n) {
			x = n;
			y++;
			pd = -1;
		}
		if (x < 1) {
			x = 1;
			y++;
			pd = 1;
		}
	}
	cout << y << ' ' << x;
	return 0;
}
