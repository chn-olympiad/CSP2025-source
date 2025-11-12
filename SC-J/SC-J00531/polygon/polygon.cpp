#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10, mod = 998244353;
int l[maxn];
long long ans, dp[maxn], p[maxn];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", l + i);
	sort(l + 1, l + 1 + n);
	dp[0] = 1, p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * 2) % mod;
	for (int i = 1; i <= n; i++) {
		if (i >= 3) {
			(ans += p[i - 1] - 1) %= mod; // 不能不选,方案数减一 
			for (int j = 1; j <= l[i]; j++) (ans += mod - dp[j]) %= mod;
		}
		for (int j = 5000; j >= l[i]; j--) (dp[j] += dp[j - l[i]]) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}// 80 min AK(?),I'm truly powerful