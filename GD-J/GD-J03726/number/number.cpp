#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool cmp(ll x, ll y) {
	return x > y;
};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll ans[1000006], a = 0;
	string s;
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (ll(s[i]) <= 57 && ll(s[i]) >= 48) {
			ans[a] = ll(s[i]) - 48;
			cout << ans[a] << " 111 " << a << endl;
			a++;
		}
	}
	cout << a;
	sort(ans, ans + a, cmp);
	for (ll i = 0; i < a; i++) {
		cout << ans[i];
	}
	return 0;
}
