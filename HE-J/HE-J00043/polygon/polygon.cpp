#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;
const int MAXN = 5010;
int n, a[MAXN];
ll s[MAXN], ans, fac[MAXN], invfac[MAXN], sum;
int mx;
ll dp[MAXN];
ll power(ll a, ll b) {
	ll r = 1;
	while(b) {
		if (b & 1) r = r * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return r;
}
ll C(int n, int m) {
	if (n < 0 || n < m) return 0LL;
	return fac[n] * invfac[m] % mod * invfac[n - m];
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	invfac[n] = power(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1) % mod;
	if (n <= 21) {
		int mas = (1 << n);
		for(int i = 1; i < mas; i++) {
			if (__builtin_popcount(i) < 3) continue;
			for(int bit = 0; bit < n; bit++) {
				if ((i >> bit) & 1) {
					mx = max(mx, a[bit + 1]);
					sum += a[bit + 1];
				}
			}
			if (sum > mx * 2) {
				ans = (ans + 1) % mod;
			}
			sum = mx = 0;
		}
	} else {
		sort(a + 1, a + n + 1);
		for(int i = 3; i <= n; i++) {
			ll c = 0;
			for(int j = 1; j < i; j++) {
				int L = j, R = i;
				while(L + 1 < R) {
					int mid = L + R >> 1;
					if (a[j] + s[i] - s[mid - 1] <= a[i]) L = mid;
					else R = mid;
				}
				for(int k = 2; k <= i - R; k++) c = (c + C(i - R, k) + mod) % mod;
			}
			dp[i] = (dp[i - 1] + c) % mod;
		}
		ans = dp[n];
	}
	printf("%lld\n", ans);
	return 0;
}
