#include <bits/stdc++.h>
using namespace std;
// polygon
const int N = 5005;
using ll = long long;
const ll Mod = 998244353;
void add(ll &a, ll b) {
	a %= Mod; b %= Mod;
	a += b; a %= Mod;
}
int n, a[N];
ll pow2[N], dp[N], s[N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n); 
	pow2[0] = 1;
	for (int i = 1; i <= n; i ++ )
		pow2[i] = (pow2[i - 1] * 2) % Mod;
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	ll ans = 0; dp[0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		if (i >= 3)
			add(ans, pow2[i - 1] - s[a[i]] - 1ll);
		for (int j = N - 1; j >= a[i]; j -- ) 
			add(dp[j], dp[j - a[i]]);
		for (int j = 0; j < N; j ++ ) s[j] = 0;
		for (int j = 1; j < N; j ++ )
			s[j] = (s[j - 1] + dp[j]) % Mod;
	}
	ans = (ans + Mod) % Mod;
	printf("%lld\n", ans);
	return 0;
}

// I like 20230237!
