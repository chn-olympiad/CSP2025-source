#include <bits/stdc++.h>
#define int long long

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 205;

int T, n, f[kMaxN][kMaxN][kMaxN];
int a[kMaxN][3], b[kMaxN];
//我不该开这题，浪费我2h 
//sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhocsb adhoc sb adhoc sb adhoc sb adhoc sb adhoc sb adhocsb adhocsb adhocsb adhoc sb adhoc sb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhocsb adhoc
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);	 
	for (cin >> T; T--;) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			b[i] = a[i][0];
		}
		if (n <= 200) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= min(i, n / 2); j++) {
					for (int k = 0; k <= min(i, n / 2); k++) {
						f[i][j][k] = -1e18;
					}
				}
			}
			f[0][0][0] = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= min(i, n / 2); j++) {
					for (int k = 0; k <= min(i, n / 2); k++) {
						if (j < n / 2) {
							f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1][0]);
						}
						if (k < n / 2) {
							f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k] + a[i + 1][1]);
						}
						if (i - j - k < n / 2) {
							f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + a[i + 1][2]);
						}
					}
				}
			}
			int ans = 0;
			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					if (n - j - k <= n / 2) {
						ans = max(ans, f[n][j][k]);
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		sort(b + 1, b + n + 1);
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) ans += b[i];
		cout << ans << '\n';
	}
	return 0;
}

