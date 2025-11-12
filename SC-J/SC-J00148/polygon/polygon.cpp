#include <iostream>
#define ll long long
#define MOD 998244353
using namespace std;
int n, m, fl;
ll c;
ll fac[5005], inv[5005];
int a[5005], b[5005];
void dfs(int x, int mx, ll s) {
	if (2 * mx < s && m >= 3) {
		c++;
	}
	if (x > n) return;
	
	for (int i = x + 1; i <= n; ++i) {
		b[++m] = i;
		dfs(i, max(mx, a[i]), s + a[i]);
		--m;
	}
}
ll qpow(ll a, ll b) {
	ll s = 1;
	while (b) {
		if (b & 1) {
			s = (s * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return s;
}
void init() {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = qpow(fac[i], MOD - 2);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	fl = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) {
			fl = 0;
		}
	}
	if (fl) {
		init();
		for (int i = 3; i < n; ++i) {
			c = (c + fac[n] * inv[n - i] % MOD * inv[i] % MOD) % MOD;
		}
		cout << c + 1;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		b[++m] = i;
		dfs(i, a[i], a[i]);
		--m;
	}
	cout << c;
	return 0;
}