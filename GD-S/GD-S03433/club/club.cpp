#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int a[maxn][3], n;
ll ans, dp[210][210][210];
void dfs(int i, int cnt1, int cnt2, int cnt3, ll sum) {
	if (i > n) ans = max(ans, sum);
	if (cnt1 < n / 2) dfs(i + 1, cnt1 + 1, cnt2, cnt3, sum + a[i][0]);
	if (cnt2 < n / 2) dfs(i + 1, cnt1, cnt2 + 1, cnt3, sum + a[i][1]);
	if (cnt3 < n / 2) dfs(i + 1, cnt1, cnt2, cnt3 + 1, sum + a[i][2]);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int x = min(i, n / 2); x >= 0; x--) {
				for (int y = min(i, n / 2); y >= 0; y--) {
					for (int z = min(i, n / 2); z >= 0; z--) {
						if (x + y + z != i) continue;
						if (x) dp[x][y][z] = max(dp[x][y][z], dp[x-1][y][z] + a[i][0]);
						if (y) dp[x][y][z] = max(dp[x][y][z], dp[x][y-1][z] + a[i][1]);
						if (z) dp[x][y][z] = max(dp[x][y][z], dp[x][y][z-1] + a[i][2]);
						if (i == n) ans = max(ans, dp[x][y][z]);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
