#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], cnt, x, y;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) {
		cin >> a[i];
		a[i] >= a[1] ? ++cnt : 0;
	}
	y = cnt / m + (cnt % m > 0 ? 1 : 0);
	if(cnt % (m << 1) > m)
		x = m - (cnt % m == 0 ? m : cnt % m) + 1;
	else
		x = (cnt % m == 0 ? m : cnt % m);
	cout << y << ' ' << x;
	return 0;
}
