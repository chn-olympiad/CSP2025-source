#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5007;
const ll P = 998244353;
ll n;
ll ans;
ll a[N];

ll qpow(ll a, ll b) {
	ll x = 1;
	while (b) {
		if (b & 1) {
			x = x * a % P;
		}
		a = a * a % P;
		b = b >> 1;
	}
	return x % P;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (ll i = 3; i <= n; ++i) {
		ll tot = 1;
		for (ll j = n; j >= n - i + 1; --j) {
			tot = tot * j;
		}
		ll sum = 1;
		for (ll j = i; j >= 1; --j) {
			sum = sum * j;
		}
		ans = (ans + tot / sum) % P;
	}
	
	cout << ans % P;
	
	return 0;
}