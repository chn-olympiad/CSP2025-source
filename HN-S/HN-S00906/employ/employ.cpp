#include<bits/stdc++.h>
using namespace std;
int c[510], mod = 998244353;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	string s; cin >> s;
	for(int i = 1; i <= n; i ++) {
		cin >> c[i];
		if(!c[i]) ++ cnt;
	}
	int len = s.size(), cnt_s = 0;
	for(int i = 0; i <= len - 1; i ++) {
		if(s[i] == '1') ++ cnt_s;
	}
	if(cnt_s == n) {
		long long ans = 1;
		for(int i = 2; i <= n - cnt; i ++) {
			ans *= i;
			ans %= mod;
		}
		cout << ans << '\n';
	} else {
		cout << cnt << '\n';
	}
	return 0;
}
