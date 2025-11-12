#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[5005], b;
ll ans;
void ss(ll i, ll bi, ll h, ll ma) {
	if (bi>=3) {
		if (h > ma * 2) {
			ans += 1;
			ans %= 998244353;
		}
	}
	for (ll j = i; j <= n; j++) {
		ss(j + 1, bi + 1, h+a[j], a[j]);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ss(1, 0, 0, 0);
	cout << ans;
	return 0;
}