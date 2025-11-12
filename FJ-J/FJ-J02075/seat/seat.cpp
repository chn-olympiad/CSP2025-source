#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e3 + 2;

int n, m, a[N], xr, x, y = 1, mx = 1, my, pos, l = 1, t;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	xr = a[1];
	t = n;
	sort(a + 1, a + 1 + n * m, cmp);
	while (1) {
		if (x == t) mx = 0, my = 1, t = (n - t + 1);
		x += mx;
		y += my;
		pos++;
//		cout << x << " " << y << " " << pos << " " << a[pos] << endl;
		if (mx == 0 && my == 1) mx = -l, my = 0, l = mx;
		if (a[pos] == xr) {
			cout << y << " " << x << endl;
			return 0;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
