#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, a[500005], cnt;

bool f(ll l, ll r) {
	ll ans = a[l];
	for (ll i = l + 1; i <= r; i++) {
		ans ^= a[i];
	}
	return ans == k;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			bool fg = f(i, j);
			if (fg) {
				cnt++, i = j + 1;
			}
		}
	}
	cout << cnt;
	return 0;
}
