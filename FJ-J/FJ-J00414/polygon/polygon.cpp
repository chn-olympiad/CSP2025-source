#include <bits/stdc++.h>
typedef long long ll;
const int N = 5005;
const ll mod = 998244353;
const ll inv = mod + 1 >> 1;
inline int min(const int a, const int b) { return a < b ? a : b; }

ll ksm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod; b >>= 1; 
	} return res;
}

int n; ll a[N];
ll f[N][3], ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n); ans = (ksm(2, n) + mod - 1 - n + mod - (ll)n * (n - 1) % mod * inv % mod) % mod;
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	std::sort(a + 1, a + 1 + n); f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= a[i]; ++j) 
			ans = (ans + mod - f[j][2]) % mod;
		for (int k = 2; ~k; --k) 
			for (int j = a[n] - a[i]; j >= 0; --j) 
				(f[j + a[i]][min(k + 1, 2)] += f[j][k]) %= mod;
	} printf("%lld", (ans + mod) % mod);
	
	return 0;
}
