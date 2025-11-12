#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n;
ll a[5005];
ll g[5005][5005];
ll pow2[5005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	pow2[0] = 1;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		pow2[i] = pow2[i - 1] * 2 % mod;
	}
	sort(a + 1, a + n + 1);
	a[n + 1] = 5000;
	for (int i = 0; i <= 5000; i++) g[0][i] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= 5000; j++) {
			g[i][j] = g[i - 1][j];
			if (j >= a[i]) {
				g[i][j] = (g[i][j] + g[i - 1][j - a[i]]) % mod;
			}
		}
	}
	ll res = 0;
	for (ll i = 3; i <= n; i++) {
		ll temp = (pow2[i - 1] - g[i - 1][a[i]] + mod) % mod;
		res = (res + temp) % mod;
	}
	cout << res << '\n';
	return 0;
}