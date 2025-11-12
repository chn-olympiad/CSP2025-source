#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
int k, m, n, a[10][N], o2[N], fa[N], ans = INT_MAX;
bitset<20> vis;

struct way{
	int u = 0, v = 0, w = 0;
	bool operator<(const way & cmp) const {
		return w < cmp.w;
	}
};
vector<way> edge;

int fid(int x) { return fa[x] = (fa[x] == x ? x : fid(fa[x])); }

int merge(way x) {
	int fx = fid(x.u), fy = fid(x.v);
	if (fx != fy) {
		fa[fx] = fy;
		return x.w;
	}
	return 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	for (int i = 1;i <= k;++i) {
		cin >> o2[i];
		for (int j = 1;j <= n;++j) cin >> a[i][j];
	}
	for (int i = 1;i <= n;++i) fa[i] = i;
	sort(edge.begin(), edge.end());
	for (auto i : edge) ans += merge(i);
	cout << ans;
	return 0;
}

/*
MST!
As k is so small, it seems that I can try to solve the problem by thinking about it;
About 64 pts, but seems impossible to get(hopefully Ultra 9-285K Qwq)
*/
