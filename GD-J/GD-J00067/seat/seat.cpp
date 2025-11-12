#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N], xr, x = 1, y = 1;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n>> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	xr = a[1];
	sort(a + 1, a + 1 + (n * m), cmp);
	for (int i = 1; i <= (n * m); i ++) {
		if (a[i] == xr) {
			cout << x << " " << y;
			return 0;
		}
		if (y == n && x % 2 == 1) {
			x ++;
			continue ;
		}
		if (y == 1 && x % 2 == 0) {
			x ++;
			continue ;
		}
		if (x % 2 == 1) {
			y ++;
		} else {
			y --;
		}
	}
	return 0;
}

