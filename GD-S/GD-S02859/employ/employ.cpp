#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n, m;
char s[N];
int c[N];
int a[N], vis[N];
int cnt, res;
void dfs(int x) {
	if (x == n + 1) {
		cnt = 0;
		for (int i=1; i<=n; i++) {
			if (s[i] == '0') {
				++cnt;
				continue;
			}
			if (cnt >= c[a[i]])
				++cnt;
		}
		res += (cnt <= n-m);
		return;
	}
	for (int i=1; i<=n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		a[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];
	dfs(1);
	cout << res << '\n';
	return 0;
}
