#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], c[500010];
int dp[500010];
int mp[1 << 21];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	freopen("xor1.in", "r", stdin);
//	freopen("t.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
	int x = 0;
	memset(mp, 255, sizeof(mp));
	mp[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		x ^= a[i];
		c[i] = mp[x ^ k];
		mp[x] = i;
	}
	for (int i = 1 ; i <= n ; i++) {
		dp[i] = dp[i - 1];
		if (c[i] > -1)
			dp[i] = max(dp[i], dp[c[i]] + 1);
	}
	printf("%d\n", dp[n]);
	return 0;
}
