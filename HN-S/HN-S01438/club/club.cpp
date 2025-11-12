#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 203, MAXN = 1e5 + 3;

int t, n;

int a[kMaxN][4];

int dp[kMaxN][kMaxN][kMaxN];

int aa[MAXN];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for (cin >> t; t; t--) {
		cin >> n;
		if (n <= 200) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> a[i][j];
				}
			}
			memset (dp, 0, sizeof dp);
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = i - j - n / 2; k <= n / 2; k++) {
						if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
						if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
						if (i - j - k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
	//					dp[i][j][k] = max({dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1], dp[i - 1][j][k - 1] + a[i][2], dp[i - 1][j][k] + a[i][3]});
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = i - j - n / 2; k <= n / 2; k++) {
						ans = max(ans, dp[i][j][k]);
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cin >> aa[i];
			for (int j = 1, x; j <= 2; j++) {
				cin >> x;
			}
		}
		sort (aa + 1, aa + 1 + n);
		int ans = 0;
		for (int i = n, cnt = 1; i >= 1 && cnt <= n / 2; i--, cnt++) {
			ans += aa[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
