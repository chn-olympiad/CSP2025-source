#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

string s;
int n, m, ans, t[505], c[505], dis[505], p[505];

void dfs (int k) {
	if (k >= n) {
		int l = 0, sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (c[p[i]] <= l || t[i] == 0) l ++;
			else sum ++;
		}
		if (sum >= m) ans ++; ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (dis[i] == 1) continue;
		dis[i] = 1; p[k + 1] = i; dfs (k + 1); dis[i] = 0;
	}
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < s.size (); i ++) t[i + 1] = s[i] - '0';
	for (int i = 1; i <= n; i ++) cin >> c[i];
	dfs (0);
	cout << ans << "\n";
	return 0;
}
