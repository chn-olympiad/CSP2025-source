#include <bits/stdc++.h>
typedef long long ll;
const int N = 505;
const int mod = 998244353;

int n, k, s[N], a[N], ans;
ll f[1 << 18][N];
 
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%1d", s + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	if (k == n) { 
		for (int i = 0; i < n; ++i) if (!a[i]) { puts("0"); return 0; }
		for (int i = 0; i < n; ++i) if (!s[i]) { puts("0"); return 0; } 
		ll ans = 1;
		for (int i = 1; i <= n; ++i) ans = ans * i % mod;
		printf("%lld", ans);
		return 0; 
	}
	f[0][0] = 1;
	for (int S = 0; S < 1 << n; ++S) {
		int cnt = __builtin_popcount(S);
		for (int i = 0; i <= cnt; ++i) {
			if (f[S][i]) {
				int T = ((1 << n) - 1) ^ S; 
				for (int j = __builtin_ctz(T & -T); T; T ^= T & -T, j = __builtin_ctz(T & -T)) {
					if (i >= a[j] || !s[cnt]) (f[S | 1 << j][i + 1] += f[S][i]) %= mod;
					else (f[S | 1 << j][i] += f[S][i]) %= mod; 
				}
			}
		}
	}
	for (int i = n - k; ~i; --i) (ans += f[(1 << n) - 1][i]) %= mod;
	printf("%d", ans);  
	return 0;
}
