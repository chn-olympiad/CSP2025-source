#include <bits/stdc++.h>

using namespace std;

int t, n, topa, topb, topc;
long long a[100100], b[100100], c[100100], d[4][100100], ans;

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	for (int o = 1; o <= t; o++) {
		scanf ("%d", &n);
		topa = 0, topb = 0, topc = 0, ans = (long long)0;
		for (int i = 1; i <= n; i++) {
			scanf ("%lld%lld%lld", &a[i], &b[i], &c[i]);
			if (a[i] > b[i] && a[i] > c[i]) {
				ans += a[i];
				if (b[i] > c[i]) {
					d[1][++topa] = a[i] - b[i];
				} else {
					d[1][++topa] = a[i] - c[i];
				}
			} else if (b[i] > c[i]) {
				ans += b[i];
				if (a[i] > c[i]) {
					d[2][++topb] = b[i] - a[i];
				} else {
					d[2][++topb] = b[i] - c[i];
				}
			} else {
				ans += c[i];
				if (a[i] > b[i]) {
					d[3][++topc] = c[i] - a[i];
				} else {
					d[3][++topc] = c[i] - b[i];
				}
			}
		}
		if (2 * topa > n) {
			sort (d[1] + 1, d[1] + topa + 1);
			for (int i = 1; i <= topa - n / 2; i++) {
				ans -= d[1][i];
			}
		}
		if (2 * topb > n) {
			sort (d[2] + 1, d[2] + topb + 1);
			for (int i = 1; i <= topb - n / 2; i++) {
				ans -= d[2][i];
			}
		}
		if (2 * topc > n) {
			sort (d[3] + 1, d[3] + topc + 1);
			for (int i = 1; i <= topc - n / 2; i++) {
				ans -= d[3][i];
			}
		}
		printf ("%lld\n", ans);
	}
}
