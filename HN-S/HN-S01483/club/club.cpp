#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 305;
int n, ans, a[N][3], dp[M][M][M], c1, c2, sum;
vector<int> d1, d2, d3;
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			c1 += (a[i][1] == 0);
			c2 += (a[i][2] == 0);
		} 
		if (n <= 200) {
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						int l = i - j - k;
						if (j + k > i || l > n / 2) continue;
						if (j >= 1) dp[i][j][k] = max(dp[i - 1][j - 1][k] + a[i][0], dp[i][j][k]);
						if (k >= 1) dp[i][j][k] = max(dp[i - 1][j][k - 1] + a[i][1], dp[i][j][k]);
						if (l >= 1) dp[i][j][k] = max(dp[i - 1][j][k] + a[i][2], dp[i][j][k]);
					}
				}
			}
			int ans = 0;
			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					ans = max(ans, dp[n][j][k]);
				}
			}
			cout << ans << '\n';
		} else if (c1 == n && c2 == n) {
			d1.clear();
			for (int i = 1; i <= n; i++) {
				d1.push_back(a[i][0]);
			}
			sort(d1.begin(), d1.end(), [](int x, int y) {
				return x > y;
			});
			int ans = 0;
			for (int i = 0; i < n / 2; i++) ans += d1[i];
			cout << ans << '\n';
		} else {
			sum = 0;
			d1.clear();
			d2.clear();
			d3.clear();
			for (int i = 1; i <= n; i++) {
				int mx = max({a[i][0], a[i][1], a[i][2]});
				if (a[i][0] == mx) {
					d1.push_back(i);
					sum += a[i][0];
				} else if (mx == a[i][1]) {
					d2.push_back(i);
					sum += a[i][1];
				} else if (mx == a[i][2]) {
					d3.push_back(i);
					sum += a[i][2];
				}
			}
			if (d1.size() <= n / 2 && d2.size() <= n / 2 && d3.size() <= n / 2) {
				cout << sum << '\n';
			} else if (d1.size() > n / 2) {
				sort(d1.begin(), d1.end());
				for (int i = 0; i < d1.size() - n / 2; i++) {
					sum -= a[d1[i]][0];
					sum += max(a[d1[i]][1], a[d1[i]][2]);
				}
				cout << sum << '\n';
			} else if (d2.size() > n / 2) {
				sort(d2.begin(), d2.end());
				for (int i = 0; i < d2.size() - n / 2; i++) {
					sum -= a[d2[i]][1];
					sum += max(a[d2[i]][0], a[d2[i]][2]);
				}
				cout << sum << '\n';
			} else {
				sort(d3.begin(), d3.end());
				for (int i = 0; i < d3.size() - n / 2; i++) {
					sum -= a[d3[i]][2];
					sum += max(a[d3[i]][0], a[d3[i]][1]);
				}
				cout << sum << '\n';
			}
		}
	}
	return 0;
}
