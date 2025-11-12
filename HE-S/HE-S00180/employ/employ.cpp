#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 10;
const int p = 998244353;

int n, m, ans;
char s[N];
bool vis[N];
int a[N], c[N];

void dfs (int x) {
	if (x == n + 1) {
		int sum = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			if (sum >= c[a[i]]) { sum++; continue; }
			if (s[i] == '0') { sum++; continue; }
			res++;
		} if (res >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) a[x] = i, vis[i] = 1, dfs (x + 1), vis[i] = 0;
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i) cin >> c[i];
	bool flag = 1;
	for (int i = 1; i <= n; ++i) if (s[i] == '0') flag = 0;
	if (m == n && flag) {
		ans = 1;
		int x = 0;
		for (int i = 1; i <= n; ++i) if (!c[i]) x = 1;
		for (int i = 1; i <= n; ++i) ans = ans * i % p;
		if (x) cout << 0;
		else cout << ans;
		return 0;
	}
	dfs (1);
	cout << ans;
	return 0;
}
