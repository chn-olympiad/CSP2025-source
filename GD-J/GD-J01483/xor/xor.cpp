#include <bits/stdc++.h>
using namespace std;
// xor
const int N = 5e5 + 5;
const int V = 1048576;
int dp[N], s[N], pre[V];
int n, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k); 
	for (int i = 1; i <= n; i ++ ) {
		int tp; scanf("%d", &tp);
		s[i] = s[i - 1] ^ tp;
	}
	memset(pre, -1, sizeof pre);
	pre[0] = 0;
	for (int i = 1; i <= n; i ++ ) {
		dp[i] = dp[i - 1];
		int j = s[i] ^ k;
		if (pre[j] != -1) dp[i] = max(dp[i], dp[pre[j]] + 1);
		if (pre[s[i]] == -1 || dp[pre[s[i]]] < dp[i])
			pre[s[i]] = i;
	}
	printf("%d\n", dp[n]);
	return 0;
}

// hope 2e6 ints of memory is ok...
