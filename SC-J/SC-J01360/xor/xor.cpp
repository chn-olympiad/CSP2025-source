#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e5 + 7;
ll ans;
ll n, k;
ll a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	bool fl = false;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) {
			fl = true;
		}
	}
	
//	cout << cnt << '\n';
	
	if (k == 0 && !fl) {
		cout << n / 2;
		return 0;
	}
	
	for (ll i = 1; i <= n; ++i) {
		ll tot = 0;
		ll sum = 0;
		for (ll l = i; l <= n; ++l) {
			tot = tot ^ a[l];
			if (tot == k) {
				++sum;
				tot = 0;
			}
		}
		ans = max(ans, sum);
	}
	
	cout << ans;
	
	return 0;
}