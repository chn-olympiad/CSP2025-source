#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
#define mod 998244353
using namespace std;

inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

ll a[5003], f[5003][10004], g[5003][10004];

ll pw(ll x, ll y) {
	ll res = 1;
	for(; y; y >>= 1, x = x * x % mod) if(y & 1) res = res * x % mod;
	return res; 
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ll n = rd();
	for(ll i = 1; i <= n; i++) a[i] = rd();
	sort(a + 1, a + n + 1);
	g[0][0] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j <= a[n] * 2; j++) {
			g[i][j] = g[i - 1][j];
			if(j >= a[i]) g[i][j] = (g[i][j] + g[i - 1][j - a[i]]) % mod;
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j <= a[i] * 2; j++) {
			f[i][j] = f[i - 1][j]; 
			if(j >= a[i]) f[i][j] = (f[i][j] + g[i - 1][j - a[i]]) % mod;
		}
	}
	ll ans = (pw(2, n) - 1 + mod) % mod; 
	for(ll i = 1; i <= a[n] * 2; i++) ans = (ans - f[n][i] + mod) % mod;
	cout << ans;
	return 0;
}
/*
由于最长边只有一个，考虑反着做。 

排序是显然的，这样选到的最后一个数就一定是最大的。

设 $g_{i,j}$ 表示选到第 $i$ 个，和为 $j$ 所有的方案数，则有 $g_{i,j} = g_{i - 1,j} + g_{i - 1, j - a_i}$。

设 $f_{i,j}$ 表示选到第 $i$ 个，和为 $j$ 非法的方案数，则有 $f_{i,j} = f_{i - 1,j} + g_{i - 1, j - a_i}$。

由于 $g_{i,j}$ 是为 $f_{i,j}$ 服务的，所以 $j$ 的上界是 $2a_n$。

由于 $f_{i,j}$ 是求非法的数量，所以 $j$ 的上界是 $2a_i$。

最后容斥一下即可。 

g[i][j] = g[i - 1][j] + g[i - 1][j - a[i]]

f[i][j] = f[i - 1][j] + g[i - 1][j - a[i]]
*/

