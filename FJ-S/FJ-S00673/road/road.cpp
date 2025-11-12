#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10005, M = 1000005;
int n, m, k, c[15], a[15][N];
vector<pair<int, int> > e[N];

bool Open[15];
priority_queue<pair<int, int> > Q;
int cnt, ans, minn = 0x3f3f3f3f;
bool vis[N + 10];
int MinTree(int etc) {
	memset(vis, 0, sizeof(vis));
	while (!Q.empty()) Q.pop(); cnt = ans = 0;
	Q.push({0, 1});
	while (cnt < n + etc) {
		int W = -Q.top().first, s = Q.top().second; Q.pop();
		if (vis[s]) continue; vis[s] = 1, ans += W, cnt++;
//		cout << s << ' ' << W << endl;
		if (s <= n) {
			for (int i = 0; i < e[s].size(); i++) {
				int u = e[s][i].first, w = e[s][i].second;
				Q.push({-w, u});
			}
			for (int j = 1; j <= 10; j++) if (Open[j]) {
				Q.push({-a[j][s], n + j});
			}
		} else {
			for (int i = 1; i <= n; i++) Q.push({-a[s - n][i], i});
		}
	} return ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool Q = 1;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({v, w}); e[v].push_back({u, w});
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j]; Q = Q && (c[j] == 0);
		for (int i = 1; i <= n; i++) cin >> a[j][i];
	}
	if (0) {
		for (int j = 1; j <= k; j++) Open[j] = 1;
		cout << MinTree(k);
		return 0;
	}
	for (int i = 0; i < (1 << k); i++) {
		int Ans = 0, etc = 0;
		for (int j = 1; j <= k; j++) {
			Open[j] = i & (1 << (j - 1));
			if (Open[j]) Ans += c[j], etc++;
		} minn = min(minn, Ans + MinTree(etc));
	} cout << minn;
}
