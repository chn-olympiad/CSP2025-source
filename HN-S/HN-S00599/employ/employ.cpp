#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, mod = 998244353;

string s;

int n, m, p[N], c[N], ans, sum[N];

bool vis[N];

bool check() {
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt >= c[p[i]]) {
			cnt ++;
			continue;
		}
		res += (s[i] == '1');
		cnt += (s[i] == '0');
	}
	return res >= m;
}

void dfs(int cur) {
	if (cur == n + 1) {
		ans += check();
		ans %= mod;
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = true;
			p[cur] = i;
			dfs(cur + 1);
			vis[i] = false;
		}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = "#" + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum[i] = sum[i - 1] + (s[i] == '0');
	}
	dfs(1);
	cout << ans;
	return 0;
}
// unsigned long long CSP_S_2025_RP = -1;
