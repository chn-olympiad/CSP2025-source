#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string t1, t2;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	vector<pair<string, string>> s(n + 1);
	vector<bool> st(n + 1);
	map<string, set<string>> mp;
	map<pair<string, string>, int> mp_idx;
	for(int i = 1; i <= n; ++ i){
		cin >> s[i].first >> s[i].second;
		mp_idx[{ s[i].first, s[i].second }] = i;
		mp[s[i].first].insert(s[i].second);
	}
	auto dfs = [&](int x, int buf_sta, auto&& dfs) -> void {
		//cout << "x:" << x << "bs:" << buf_sta;
		if(x >= t1.size()) {
			if(x == buf_sta)
				++ ans/*, cout << "ok"*/;
			//cout << '\n';
			return;
		}
		//cout << '\n';
		dfs(x + 1, buf_sta, dfs);
		if(buf_sta == x && t1[x] == t2[x])
			dfs(x + 1, buf_sta + 1, dfs);
		else if(mp[t1.substr(buf_sta, x - buf_sta + 1)].count(t2.substr(buf_sta, x - buf_sta + 1))) {
			int t = mp_idx[{ t1.substr(buf_sta, x - buf_sta + 1), t2.substr(buf_sta, x - buf_sta + 1) }];
			if(st[t]) return;
			st[t] = true;
			//cout << "x:" << x << "bs:" << buf_sta << "use:" << t << '\n';
			dfs(x + 1, x + 1, dfs);
			st[t] = false;
		}
	};
	for(int i = 1; i <= q; ++ i) {
		cin >> t1 >> t2;
		ans = 0;
		dfs(0, 0, dfs);
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 1
ab cd
bc de
aa bb
xabcx xadex
*/
