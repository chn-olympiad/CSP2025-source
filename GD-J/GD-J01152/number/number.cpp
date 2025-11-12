#include <bits/stdc++.h>
//#define int long long

using namespace std;

int tot[15];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9') tot[s[i] - '0'] ++;
	}
	string ans;
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= tot[i]; j ++) ans += (i + '0');
	}
	cout << ans;
	return 0;
}
