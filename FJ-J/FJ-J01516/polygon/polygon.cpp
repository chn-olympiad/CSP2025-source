#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;

int n, dp[10200], a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	freopen("polygon1.in", "r", stdin);
//	freopen("t.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	dp[0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = a[i] + 1 ; j <= 10100 ; j++)
			ans = (ans + dp[j]) % p;
		for (int j = 10100 ; j >= a[i] ; j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % p;
		for (int j = 5011 ; j <= 10100 ; j++)
			dp[5010] = (dp[5010] + dp[j]) % p, dp[j] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
