#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 502, MD = 998244353;
int n, m, s[N], c[N], t[N], st[N], res;
int check() {
	int tot = 0; // 成功人数 
	for (int i = 1; i <= n; i++)
		if (i - tot - 1 < t[i] && s[i]) tot++;
	return tot >= m;
}
void dfs(int u) {
	if (u == n + 1) return res += check(), void();
	for (int i = 1; i <= n; i++) 
		if (!st[i]) st[i] = 1, t[u] = c[i], dfs(u + 1), st[i] = 0;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		char cc; cin >> cc;
		s[i] = cc - '0', f = f & s[i];
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (f) {
		int res = 1;
		for (int i = 1; i <= n; i++) res = res * i % MD;
		cout << res;
	} else dfs(1), cout << res;
	return 0;
}
/*
*/
