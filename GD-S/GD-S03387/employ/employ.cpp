#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 998244353;
bool vis[N];
int s[N];
int c[N];
int n, m;
long long ans;

void dfs(int x, int step, int noPeo) {
	if (!s[step] || noPeo >= c[x]) noPeo++;
	if (step == n) {
		//cout << n - noPeo << "\n";
		if (n - noPeo >= m) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	vis[x] = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, step + 1, noPeo);
		}
	}
	vis[x] = false;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%1d", &s[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) {
		dfs(i, 1, 0);
	}
	cout << ans;
	return 0;
}
