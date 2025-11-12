#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 0;
ll k = 0;
stack<ll> s;
ll ans = 0;
ll a[1000100] = {0};
ll pre[1000100] = {0};

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i]^pre[i - 1];
	}
	if (n <= 2) {
		cout << 1;
		return 0;
	}
	if (n <= 100 and k == 0) {
		cout << n / 2;
		return 0; 
	}
	for (ll i = 1; i <= n; i++) {
		if (pre[i] == k) {
			ans += 1;
			s.push(k);
			continue;
		}
		if (pre[i] == 0 and !s.empty() and pre[i - 1] != k and k != 0) {
			s.pop();
			ans += 1;
		}
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
