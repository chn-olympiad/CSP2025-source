#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int e[MAXN], f[MAXN], g[MAXN], a[5], b[5], t, n, ans, asx, asy, asz;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = asx = asy = asz = 0;
		cin >> n;
		if (n == 2) {
			cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
			for (int i = 1; i < 4; i++) {
				for (int j = 1; j < 4; j++) {
					if (i != j) ans = max(ans, a[i] + b[j]);
				}
			}
			cout << ans << endl;
		} else {
			bool flag = 0;
			for (int i = 1; i <= n; i++) {
				cin >> e[i] >> f[i] >> g[i];
				if (e[i] >= f[i] && e[i] >= g[i]) asx++;
				else if (f[i] >= e[i] && f[i] >= g[i]) asy++;
				else asz++;
				if ((e[i] && !f[i] && !g[i]) || (!e[i] && f[i] && !g[i]) || (!e[i] && !f[i] && g[i])) flag = 1;
			}
			if (flag) {
				if (e[1]) sort(e + 1, e + n + 1);
				if (f[1]) sort(f + 1, f + n + 1);
				if (g[1]) sort(g + 1, g + n + 1);
				for (int i = n; i > n / 2; i--) ans += max(e[i], max(f[i], g[i]));
				cout << ans << endl;
				continue;
			}
			if (asx <= n / 2 && asy <= n / 2 && asz <= n / 2) {
				for (int i = 1; i <= n; i++) ans += max(e[i], max(f[i], g[i]));
				cout << ans << endl;
				continue;
			}
			asx = asy = asz = 0;
			for (int i = 1; i <= n; i++) {
				if (e[i] > f[i] && e[i] > g[i] && asx < n / 2) {
					asx++;
					ans += e[i];
					continue;
				}
				if (f[i] > g[i] && asy < n / 2) {
					asy++;
					ans += f[i];
					continue;
				}
				ans += g[i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}
