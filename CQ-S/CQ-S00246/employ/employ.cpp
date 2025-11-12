#include <bits/stdc++.h>

using namespace std;

namespace zcq_qwq {
	const int N = 500 + 5;
	
	int n, m;
	
	int a[N], b[N], cnt[N];
	
	bool vis[N];
	
	string s;
	
	int ans = 0;
	
	void dfs(int x) {
		if (x == n + 1) {
			int pre = 0;
			int sum = 0; 
			for (int i = 1; i <= n; i++) {
				if (s[i - 1] == '0' || pre >= a[b[i]]) {
					pre++;
				} else {
					sum++;
				}
			}
			if (sum >= m) {
				ans++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				b[x] = i;
				vis[i] = true;
				dfs(x + 1);
				vis[i] = false;
			}
		}
	}
	
	void main() {
		cin >> n >> m;
		cin >> s;
		for (int i = 1; i <= n; i++) {
			cnt[i] = cnt[i - 1] + (s[i - 1] == '1');
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(1);
		cout << ans;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

