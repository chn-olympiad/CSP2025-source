#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 5000 + 15, mod = 998244353;

int n, a[N];
ll fac[N], inv[N];

ll qpow (ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

void init () {
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= N - 15; ++ i) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = qpow (fac[i], mod - 2);
//		printf ("%lld %lld\n", fac[i], inv[i]);
	}
}

ll C (ll n, ll m) {
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf ("%d", &a[i]);
	if (n <= 3) {
		if (n < 3) printf ("0\n");
		else {
			sort (a + 1, a + n + 1);
			if (a[1] + a[2] > a[3]) printf ("1\n");
			else printf ("0\n");
		}
	} else {
		init ();
		ll ans = 0;
		for (int i = 3; i <= n; ++ i) ans = (ans + C (n, i)) % mod;
		printf ("%lld\n", ans);
	}
	return 0;
}
/*

*/