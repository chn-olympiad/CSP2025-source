#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n, m, ans, cnt1, tot;
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	vector<int> c(n + 1), pre(n + 1);
	for(int i = 1; i <= n; ++ i) {
		cin >> c[i], pre[i] = pre[i - 1] + (s[i] == '0');
		cnt1 += (s[i] == '1');
	}
	vector<int> ct(cnt1 + 1);
	for(int i = 1; i <= n; ++ i)
		if(s[i] == '1')
			ct[++ tot] = pre[i];
	sort(c.begin() + 1, c.end());
	if(n - pre[n] < m) { //impossble 
		cout << "0\n";
		return 0;
	}
	if(m == n) { //m = n
		ans = 1;
		for(int o = 2; o <= n; ++ o) ans = ans * o % mod;
		cout << ans << '\n';
		return 0;
	}
	if(pre[n] == 0) { //te shu xing zhi A
		int tot = 1;
		for(int i = m; i <= n; ++ i, ans = (ans + tot) % mod, tot = 1)
			for(int o = n; o > n - i; -- o)
				tot = tot * o % mod;
		cout << ans << '\n';
		return 0;
	}
	//bao li chu qi ji!!!!!!
	vector<bool> st(n + 1);
	auto dfs = [&](int x, int p, auto&& dfs) -> void {
		int usd = x - p - 1;
		if(x > cnt1) {
			if(usd >= m) ans = (ans + 1) % mod;
			return;
		}
		if(p > cnt1 - m) return; //jian zhi
		int t = 1;
		for( ; t <= n && ct[x] + p >= c[t]; ++ t) {
			if(st[t]) continue;
			st[t] = true;
			dfs(x + 1, p + 1, dfs);
			st[t] = false;
		}
		for( ; t <= n; ++ t) {
			if(st[t]) continue;
			st[t] = true;
			dfs(x + 1, p, dfs);
			st[t] = false;
		}
	};
	dfs(1, 0, dfs);
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
