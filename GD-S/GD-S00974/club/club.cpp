#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using f64 = double;
using f80 = long double;

#define FILE "club"
#define endl "\n"

const i64 MOD = 998244353;
const i32 N = 1e5 + 10;

i32 n, ans;
i32 a[N][3];
vector<i32> g[3];

bool cmp0(i32 x, i32 y) {
	return (a[x][2] - a[x][0]) < (a[y][2] - a[y][0]);
}
bool cmp1(i32 x, i32 y) {
	return (a[x][2] - a[x][1]) < (a[y][2] - a[y][1]);
}

bool cmp00(i32 x, i32 y) {
	return (max(a[x][1], a[x][2]) - a[x][0]) < (max(a[y][1], a[y][2]) - a[y][0]);
}
bool cmp11(i32 x, i32 y) {
	return (max(a[x][0], a[x][2]) - a[x][1]) < (max(a[y][0], a[y][2]) - a[y][1]);
}
bool cmp22(i32 x, i32 y) {
	return (max(a[x][1], a[x][0]) - a[x][2]) < (max(a[y][1], a[y][0]) - a[y][2]);
}

void solve() {
	g[0].clear(); g[1].clear(); g[2].clear();
	ans = 0;
	cin >> n;
	for (i32 i=1; i<=n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] == a[i][1]) {
			if (g[0].size() < g[1].size()) g[0].push_back(i);
			else g[1].push_back(i);
		} else {
			if (a[i][0] > a[i][1]) g[0].push_back(i);
			else g[1].push_back(i);
		}
	}
	
	for (i32 e: g[0]) ans += a[e][0];
	for (i32 e: g[1]) ans += a[e][1];
	sort(g[0].begin(), g[0].end(), cmp0);
	sort(g[1].begin(), g[1].end(), cmp1);
	while (!g[0].empty()) {
		i32 b = g[0].back();
		if (a[b][0] > a[b][2]) break;
		ans += a[b][2] - a[b][0];
		g[2].push_back(b);
		g[0].pop_back();
	}
	while (!g[1].empty()) {
		i32 b = g[1].back();
		if (a[b][1] > a[b][2]) break;
		ans += a[b][2] - a[b][1];
		g[2].push_back(b);
		g[1].pop_back();
	}
	
	if (g[0].size() > (n>>1)) {
		sort(g[0].begin(), g[0].end(), cmp00);
		while (g[0].size() > (n>>1)) {
			i32 b = g[0].back();
			ans += max(a[b][1], a[b][2]) - a[b][0];
			g[0].pop_back();
		}
	}
	if (g[1].size() > (n>>1)) {
		sort(g[1].begin(), g[1].end(), cmp11);
		while (g[1].size() > (n>>1)) {
			i32 b = g[1].back();
			ans += max(a[b][0], a[b][2]) - a[b][1];
			g[1].pop_back();
		}
	}
	if (g[2].size() > (n>>1)) {
		sort(g[2].begin(), g[2].end(), cmp22);
		while (g[2].size() > (n>>1)) {
			i32 b = g[2].back();
			ans += max(a[b][1], a[b][0]) - a[b][2];
			g[2].pop_back();
		}
	}
	
	cout << ans << endl;
}

int main() {
	freopen(FILE ".in", "r", stdin);
	freopen(FILE ".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	i32 t; cin >> t;
	while (t--) solve();
	return 0;
}
