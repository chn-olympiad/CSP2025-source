#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5, mod = 998244353;
ll n, a[N], xx;
bool fg = 0;
void dfs(int now, ll mx, ll cnt, int x, bool f) {
	if (x >= 3 && cnt > (mx * 2) && f) {
		xx = (xx + 1) % mod;
//		cout << mx << " " << cnt << " " << x << "\n";
	}
	if (now > n) return;
	dfs(now + 1, max(mx, a[now]), cnt + a[now], x + 1, 1);
	dfs(now + 1, mx, cnt, x, 0);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) fg = 1;
	}
	if (!fg) {
		ll ans=0;
		for (int i = 3; i <= n; i++) {
			ll x = 1,  z = 1;
			for (int j = i + 1; j <= n; j++) {
				x = x*j%mod;
			}
			for (int j = 1; j <= (n - i); j++) {
				z = z*j%mod;
			}	
			ans = (ans % mod + (x / z) % mod) % mod;
		}
		cout << ans % mod;
		return 0;
	}
	dfs(1, 0, 0, 0, 0);
	cout << xx % mod;
}