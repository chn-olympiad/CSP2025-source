#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 5e3 + 3;
const int mod = 998244353;

ll dp[N], a[N], f[N];

void add (ll &x, ll y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf ("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * 2 % mod;
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			ll y = 0;
			for (int j = 0; j <= a[i]; j++) add(y, dp[j]);
			add(ans, f[i - 1] - y);
		}
		for (int j = 5e3; j >= a[i]; j--) add(dp[j], dp[j - a[i]]);
	}
	printf("%lld\n", ans);
}
