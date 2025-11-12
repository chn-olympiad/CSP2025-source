#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int T, n, ans;
int a[N][4], x[N], y[N], z[N];

bool cmp (int a, int b) {
	return a > b;
}

void Main () {
	cin >> n, ans = 0;
	for (int i = 1; i <= n; ++i)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	int t1 = 0, t2 = 0, t3 = 0;
	for (int i = 1; i <= n; ++i) {
		int x1 = a[i][1], x2 = a[i][2], x3 = a[i][3];
		int mx = max (max (x1, x2), x3);
		ans += mx;
		if (mx == x1) {
			x[++t1] = max (x2, x3) - x1;
		} else if (mx == x2) {
			y[++t2] = max (x1, x3) - x2;
		} else {
			z[++t3] = max (x1, x2) - x3;
		}
	}
	int mx = max (max (t1, t2), t3);
	if (mx <= n / 2) cout << ans << '\n';
	else {
		int s = mx - n / 2;
		if (t1 == mx) {
			sort (x + 1, x + t1 + 1, cmp);
			for (int i = 1; i <= s; ++i) ans += x[i];
		} else if (t2 == mx) {
			sort (y + 1, y + t2 + 1, cmp);
			for (int i = 1; i <= s; ++i) ans += y[i];
		} else {
			sort (z + 1, z + t3 + 1, cmp);
			for (int i = 1; i <= s; ++i, cmp) ans += z[i];			
		} cout << ans << '\n';
	}
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) Main ();
	return 0;
}
