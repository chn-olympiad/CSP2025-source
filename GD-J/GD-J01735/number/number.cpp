#include <bits/stdc++.h>

using namespace std;

map <int, int> mp;

signed main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size (); i ++) {
		if (s[i] >= '0' && s[i] <= '9') mp[s[i] - '0'] ++;
	}
	string ans = "";
	for (auto v : mp) {
		int t = v.second;
		int k = v.first;
		while (t --) {
			ans += char(k + '0');
		}
	}
	for (int i = ans.size () - 1; i >= 0; i --) {
		cout << ans[i];
	}
	return 0;
}
