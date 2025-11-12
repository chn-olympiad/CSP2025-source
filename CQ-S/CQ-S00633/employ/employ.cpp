#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int Mod = 998244353, mod = 1e9 + 7, N = 510;
int a[N], fa = 1, n;
ll f[N], inv[N], ans, c[N], m, vis[N];
string s;

void dfs(int k) {
	if (k == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || sum >= f[i]) sum++;
		}
		ans += (sum <= n - m);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			f[k] = c[i];
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}

