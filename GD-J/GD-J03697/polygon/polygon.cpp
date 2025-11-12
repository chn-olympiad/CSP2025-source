#include <bits/stdc++.h>

using namespace std;

bool vis[5007];
int n, gun[5007], ans, suk = 0;
vector<int> xn;

bool check () {
	if (xn.size() < 3) return 0;
	int sum = 0, maxn = -2e9;
	for (int i = 0; i < (int)xn.size(); i++) {
		sum += xn[i];
		maxn = max(maxn, xn[i]);
	}
	if (sum > maxn * 2) return 1;
	else return 0;
}

void dfs (int dep, int sum, int maxn, int cnt) {
//	choose dep-th(y/n), sum m, max maxn, choose sum cnt
	if (sum > suk) return;
	if (vis[dep]) return;
	if (dep > n) return;
//	cout << "dep = " << dep << "  sum = " << sum << "  maxn = " << maxn << "  cnt = " << cnt << "\n";
	if (check()) ans++;
	vis[dep] = 1;
	xn.push_back(gun[dep]);
	dfs(dep + 1, sum + gun[dep], max(maxn, gun[dep]), cnt + 1);
	xn.reserve(cnt);
	dfs(dep + 1, sum, maxn, cnt);
	vis[dep] = 0;
}

/*
5
1 2 3 4 5
*/

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> gun[i];
		suk += gun[i];
	} 
	if (n == 3) {
		if (gun[1] + gun[2] + gun[3] > max(gun[1], max(gun[2], gun[3])) * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	ans = 0;
	fill(vis, vis + 5006, 0);
	dfs(0, 0, -2e9, 0);
	cout << ans;
	return 0;
}
