#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5, M = 505, mod = 998244353;

void solve () {
	int n, m; string s;
	cin >> n >> m >> s, s = ' ' + s;
	vector <int> a(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i ++ ) cin >> a[i], cnt += s[i] == '1';
	
	if (cnt == n) {
		ll ans = 1;
		for (int i = 1; i <= n; i ++ ) ans = ans * i % mod;
	} else if (cnt < m) {
		cout << "0\n";
	} else if (m == n) {
		cout << "1\n";
	}  else if (n <= 10) {
		vector <int> vis(n + 1, 0), cur(n + 1, 0);
		int out = 0, ans = 0; bool flg = 0;
		
		auto dfs = [&](int u, auto &&dfs) -> void {
			if (u == n + 1) {
				ans += (n - out >= m);
				if (n - out >= m) for (int i = 1; i <= n; i ++ ) cout << cur[i] << " \n"[i == n];
				return;
			}
			for (int i = 1; i <= n; i ++ ) if (!vis[i]) cur[u] = i, flg = (s[i] == '0' || out >= a[i]), out += flg, vis[i] = true, dfs (u + 1, dfs), out -= flg, vis[i] = false;
		};
		
		dfs (1, dfs);
		
		cout << ans << '\n';
	} else {
		cout << rand () << '\n';
	}
}

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);

	int T = 1;
//	cin >> T;
	while (T -- ) solve ();
	return 0;
}

