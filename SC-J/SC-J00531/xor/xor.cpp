#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10, maxk = 2e6 + 10;
int dp[maxn], xo[maxk];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(xo, -1, sizeof xo);
	int n, k, sum = 0;
	scanf("%d%d", &n, &k);
	xo[0] = 0;
	for (int i = 1; i <= n; i++) {
		int num; scanf("%d", &num);
		sum = sum xor num;
		if (xo[sum xor k] != -1) dp[i] = dp[xo[sum xor k]] + 1;
		dp[i] = max(dp[i], dp[i - 1]);
		xo[sum] = i;
	}
	printf("%d\n", dp[n]);
	return 0;
}