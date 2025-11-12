#include<bits/stdc++.h>
using namespace std;
int n, a[100010], b[100010], c[100010], d[50010], e[500010], f[50010];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		for (int i = 1; i <= n / 2; i++) {
			d[i] = e[i] = f[i] = 0;
		}
		d[0] = 500010, e[0] = 500010, f[0] = 500010;
		int md = 0, me = 0, mf = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (md < n / 2 && me < n / 2 && mf < n / 2) {
				if (a[i] > b[i] && a[i] > c[i]) {
					md++;
					d[md] = a[i];
					ans += a[i];
				}
				if (b[i] > a[i] && b[i] > c[i]) {
					me++;
					e[me] = b[i];
					ans += b[i];
				}
				if (c[i] > a[i] && c[i] > b[i]) {
					mf++;
					f[mf] = c[i];
					ans += c[i];
				}
			} else if (md == n / 2 && me < n / 2 && mf < n / 2) {
				int u = 0;
				for (int j = 1; j <= md; j++) {
					if (d[j] < d[u]) {
						u = j;
					}
				}
				if (d[u] < a[i] && a[i] - d[u] > b[i] && a[i] - d[u] > c[i]) {
					if (a[i] - d[u] < b[u] && b[i] > c[i]) {
						d[u] = a[i];
						e[u] = b[u];
						ans = ans - d[u] + a[i] + b[i];
					} else {
						d[u] = a[i];
						ans = ans - d[u] + a[i];
					}
				} else {
					if (b[i] > c[i]) {
						me++;
						e[me] = b[i];
						ans += b[i];
					}
					if (c[i] > b[i]) {
						mf++;
						f[mf] = c[i];
						ans += c[i];
					}
				}
			} else if (me == n / 2 && md < n / 2 && mf < n / 2) {
				int u = 0;
				for (int j = 1; j <= me; j++) {
					if (e[j] < e[u]) {
						u = j;
					}
				}
				if (e[u] < b[i] && b[i] - e[u] > a[i] && b[i] - e[u] > c[i]) {
					e[u] = b[i];
					ans = ans - e[u] + b[i];
				} else {
					if (a[i] > c[i]) {
						md++;
						d[md] = a[i];
						ans += a[i];
					}
					if (c[i] > a[i]) {
						mf++;
						f[mf] = c[i];
						ans += c[i];
					}
				}
			} else if (mf == n / 2 && md < n / 2 && me < n / 2) {
				int u = 0;
				for (int j = 1; j <= mf; j++) {
					if (f[j] < f[u]) {
						u = j;
					}
				}
				if (f[u] < c[i] && c[i] - f[u] > a[i] && c[i] - f[u] > b[i]) {
					f[u] = c[i];
					ans = ans - f[u] + c[i];
				} else {
					if (a[i] > b[i]) {
						md++;
						d[md] = a[i];
						ans += a[i];
					}
					if (b[i] > a[i]) {
						me++;
						e[me] = b[i];
						ans += b[i];
					}
				}
			} else if (md == n / 2 && me == n / 2 && mf < n / 2) {
				int u = 0;
				for (int j = 1; j <= md; j++) {
					if (d[j] < d[u]) {
						u = j;
					}
				}
				int v = 0;
				for (int j = 1; j <= me; j++) {
					if (e[j] < e[v]) {
						v = j;
					}
				}
				if (d[u] < a[i] && a[i] - d[u] > b[i] - e[v] && a[i] - d[u] > c[i]) {
					d[u] = a[i];
					ans = ans - d[u] + a[i];
				} else if (e[v] < b[i] && b[i] - e[v] > a[i] - d[u] && b[i] - e[v] > c[i]) {
					e[v] = b[i];
					ans = ans - e[v] + b[i];
				} else {
					mf++;
					f[mf] = c[i];
					ans += c[i];
				}
			} else if (md == n / 2 && mf == n / 2 && me < n / 2) {
				int u = 0;
				for (int j = 1; j <= md; j++) {
					if (d[j] < d[u]) {
						u = j;
					}
				}
				int w = 0;
				for (int j = 1; j <= mf; j++) {
					if (f[j] < f[w]) {
						w = j;
					}
				}
				if (d[u] < a[i] && a[i] - d[u] > c[i] - f[w] && a[i] - d[u] > b[i]) {
					d[u] = a[i];
					ans = ans - d[u] + a[i];
				} else if (f[w] < c[i] && c[i] - f[w] > a[i] - d[u] && c[i] - f[w] > b[i]) {
					f[w] = c[i];
					ans = ans - f[w] + c[i];
				} else {
					me++;
					e[me] = b[i];
					ans += b[i];
				}
			} else if (md < n / 2 && me == n / 2 && mf == n / 2) {
				int v = 0;
				for (int j = 1; j <= me; j++) {
					if (e[j] < e[v]) {
						v = j;
					}
				}
				int w = 0;
				for (int j = 1; j <= md; j++) {
					if (d[j] < d[w]) {
						w = j;
					}
				}
				if (f[w] < c[i] && c[i] - f[w] > b[i] - e[v] && c[i] - f[w] > a[i]) {
					d[w] = a[i];
					ans = ans - d[w] + a[i];
				} else if (e[v] < b[i] && b[i] - e[v] > c[i] - f[w] && b[i] - e[v] > a[i]) {
					e[v] = b[i];
					ans = ans - e[v] + b[i];
				} else {
					md++;
					d[md] = a[i];
					ans += a[i];
				}
			}
		}
		cout << ans << endl;
	}
}