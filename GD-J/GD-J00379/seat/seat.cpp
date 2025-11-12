#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, m, c, r;
ll a[N];
bool cmp (ll x, ll y) {
	return x > y;
}
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++ i) {
		cin >> a[i];
	}
	ll sc = a[1], rk = 0;
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; ++ i) {
		if (a[i] == sc) {
			rk = i;
			break;
		}
	}
	if (rk % n == 0) c = rk / n;
	else c = (rk / n) + 1;
	if (rk % n == 0) {
		if (c & 1) r = n;
		else r = 1;
	} else {
		if (c & 1) r = rk % n;
		else r = n - (rk % n) + 1;		
	}
	cout << c << ' ' << r << '\n';
	return 0;
}
