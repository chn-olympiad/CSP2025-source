#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[101];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll r;
	for (ll i = 0; i < n * m; i++) {
		cin >> a[i];
		if (i == 0) r = a[i];
	}
	sort(a, a + n * m, greater<int>());
	ll rr;
	for (ll i = 0; i < n * m; i++) {
		if (a[i] == r) rr = i;
	}
	bool f = true;//1向下，0向上
	ll h = 1, l = 1;
	for (ll i = 0; i < n * m; i++) {
		if (i == rr) {
			cout << l << ' ' << h;
			break;
		}
		if (f) {
			if (h + 1 <= n) {
				h++;
			} else {
				l++;
				f = false;
			}
		} else {
			if (h - 1 > 0) {
				h--;
			} else {
				l++;
				f = true;
			}
		}
	}
	return 0;
}
