//GZ-S00042 贵阳市第一中学 刘信果
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, mod = 998244353;
int n, m, s[N], c[N], ssum, flag, ans, p[N];

int vis[N];
void dfs(int k) {
	if (k == n+1) {
		int pass = 0;
		for (int i = 1; i <= n; ++i)
			if (!s[i] || pass >= c[p[i]]) pass++;
		if (n-pass >= m) ans++;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1, p[k] = i;
		dfs(k+1);
		vis[i] = 0, p[k] = 0;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		char ch; cin >> ch;
		s[i] = ch-'0';
		ssum += s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (!c[i]) flag = 1;
	}
	if (m == n) {
		ans = 1;
		for (int i = 1; i <= n; ++i)
			ans = ans*i%mod;
		if (ssum == n && !flag) cout << ans;
		else cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0; 
}
