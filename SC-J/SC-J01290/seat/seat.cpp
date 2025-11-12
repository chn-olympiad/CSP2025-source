#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, R, id = 1, x, y;// x 第几行 y 第几列
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> R;
	for (int i = 1, tmp; i < n * m; ++i) {
		cin >> tmp;
		if (tmp > R) {
			++id;
		}
	}
	if (id % n == 0) {
		y = id / n;
		if (y % 2 == 1) {
			cout << y << " " << n;
		} else {
			cout << y << " " << 1;
		}
	} else {
		y = id / n + 1;
		x = id % n;
		if (y % 2 == 1) {
			cout << y << " " << x;
		} else {
			cout << y << " " << n - x + 1;
		}
	}
	return 0;
}