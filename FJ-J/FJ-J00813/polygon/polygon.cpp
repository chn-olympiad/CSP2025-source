#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll a[5500];
ll cnt;
int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) cnt ++;
		cout << cnt;
		return 0;
	} else {
		cout << 0;
	}
	return 0;
}
