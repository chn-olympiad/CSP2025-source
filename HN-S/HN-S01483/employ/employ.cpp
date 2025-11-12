#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int n, m, a[N], vis[N], pos[N], ans;
string s;
void dfs(int x, int cnt) {
	if (n - cnt < m) return;
	if (x > n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			pos[x] = i;
			dfs(x + 1, cnt + (cnt >= a[i] ? 1 : s[x] == '0'));
			vis[i] = 0;
		}
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 100) {
		dfs(1, 0);
		cout << ans % 998244353 << '\n';
	} else {
		cout << 0 << '\n';
	}
	return 0;
}

