#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1100];
bool cmp (ll x, ll y) {
	return x > y;
}
int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i ++)
		cin >> a[i];
	ll num = a[1], cnt = 0;
	sort (a + 1, a + n * m + 1, cmp);
	for (ll i = 1; i <= n * m; i ++)
		if (a[i] == num) {
			cnt = i;
			break;
		}
	ll ans = 0;
	for (ll y = 1; y <= m; y ++) {
		if (y % 2 == 1) {
			for (ll x = 1; x <= n; x ++) {
				ans ++;
				if (ans == cnt) {
					cout << y << " " << x;
					return 0;
				}
			}
		} else {
			for (ll x = n; x >= 1; x --) {
				ans ++;
				if (ans == cnt) {
					cout << y << " " << x;
					return 0;
				}
			}
		}
	}
	return 0;
}
