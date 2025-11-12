#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505, mod = 998244353;
int n, m;
string s;
int a[MAXN], ls[MAXN], ans, vis[MAXN];
void dfs(int x, int cnt) {
	if (x == n + 1) {
		ans ++;
		ans %= mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		ls[x] = i;
		int t = cnt;
		if (s[x] == '0' || cnt >= a[i]) {
			t ++;
		}
		if (x - t + n - x < m) {
			vis[i] = 0;
			continue;
		}
		dfs(x + 1, t);
		vis[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	cin >> s; s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
