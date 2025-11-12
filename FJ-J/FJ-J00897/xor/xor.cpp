#include <bits/stdc++.h>
using namespace std;
int n, m, sum[500001], a[500001], ans, dp[500001], maxn[500001];
bool flag = 0;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] ^ a[i];
	for(int i = 1; i <= n; i ++) {
		for(int j = i - 1; j >= 0; j --) {
			if((sum[i] ^ sum[j]) == m) {
				//cout << i << ' ' << j << '\n';
				dp[i] = max(dp[i], maxn[j] + 1);
				break;
			}
		}
		maxn[i] = max(maxn[i - 1], dp[i]);
	}
	for(int i = 1; i <= n; i ++) ans = max(ans, dp[i]);
	printf("%d", ans);
	return 0;
}
/*
4 2
2 1 0 3
4 0
2 1 0 3
*/
