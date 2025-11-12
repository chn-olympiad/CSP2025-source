#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int T, n, a[N][4], tp[N], dp[2][1010][1010];

signed main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T--) {
		cin >> n;
		int ans = 0; 
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= i && j <= n / 2; j++) {
				for(int k = 0; j + k <= i && k <= n / 2; k++) {
					if(i - j - k > n / 2) {
						continue;
					}
					if(j + k != i) {
						dp[i & 1][j][k] = max({(k - 1 >= 0 ? dp[!(i & 1)][j][k - 1] + a[i][3] : 0), (j - 1 >= 0 ? dp[!(i & 1)][j - 1][k] + a[i][2] : 0), dp[!(i & 1)][j][k] + a[i][1]});
					}
					else {
						dp[i & 1][j][k] = max((k - 1 >= 0 ? dp[!(i & 1)][j][k - 1] + a[i][3] : 0), (j - 1 >= 0 ? dp[!(i & 1)][j - 1][k] + a[i][2] : 0));
					}
					if(i == n) {
						ans = max(ans, dp[i & 1][j][k]);
					}
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

