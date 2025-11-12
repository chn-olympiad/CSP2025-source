#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	ll a[n];
	ll t = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t] = (int)(s[i] - '0');
			t++;
		}
	}
	sort(a, a + t, greater<int>());
	for (ll i = 0; i < t; i++) cout << a[i];
	return 0;
}
