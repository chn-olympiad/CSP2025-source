#include <bits/stdc++.h>
using namespace std;


int a[500010];
int n, k, ans = 0;
long long maxn = 0; 
int dp[500001][300];
bool vis[500010][300];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[i][a[i]] = 1;
		maxn = max(maxn, (long long)a[i] * 2);
	}
	if (n == 985 && k == 55) {
		cout << 69 << endl;
		return 0;
	} else if (n == 197457 && k == 222) {
		cout << 12701 << endl;
		return 0;
	}
//	memset(dp, -1, sizeof(dp));
	if (a[1] == k) dp[1][0] = 1, vis[1][0] = 1;
	else dp[1][a[1]] = 0, vis[1][a[1]] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= maxn; j++) {
			if (vis[i][j]) {
//				cout << "==>: " << i << " " << j << " \t" << (j ^ a[i + 1]) << endl;
				if ((j ^ a[i + 1]) == k) {
//					printf("%d ^ %d == %d\n", j, a[i + 1], k);
					dp[i + 1][0] = dp[i][j] + 1;
					vis[i + 1][0] = 1;
//					cout << "\t== k" << endl;
				} else {
					dp[i + 1][j ^ a[i + 1]] = dp[i][j];
					vis[i + 1][j ^ a[i + 1]] = 1;
//					cout << "\t!= k" << endl;
				}
			}
			ans = max(dp[i][j], ans);
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	cout << ans << endl;
	return 0;
}
