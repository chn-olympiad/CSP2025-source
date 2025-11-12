#include <bits/stdc++.h>
#define ll long long
#define inf (ll)2e18
using namespace std;

const int N = 10110;
int n, m, K, c[15];
ll val, ans = inf;
struct edge{
	int u, v, w;
	bool operator < (const edge &y) const {
		return w < y.w;
	}
};
vector<edge> f[15], e, cop[15];

int fa[N], dep[N];
int fd(int x) {return fa[x] == x ? x : fa[x] = fd(fa[x]); }
void merge(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	fa[y] = x, dep[x] += (dep[x] == dep[y]);
}
vector<edge> kruskal(vector<edge> &ed) {
	for (int i=1; i<=n+K; ++i) fa[i] = i, dep[i] = 1;
	vector<edge> ret;
	val = 0;
	for (auto i : ed) {
		int u = fd(i.u), v = fd(i.v);
		if (u == v) continue;
		val += i.w, merge(u, v), ret.push_back(i);
	}
	return ret;
}

void dfs(int x, ll sum) {
	if (x > K) {
		kruskal(cop[x - 1]);
		if (ans > sum + val) ans = sum + val;
		// if (sum + val == 13) {
		// 	printf("sum %d\n", sum);
		// 	for (auto i : tmp) printf("u %d v %d w %d\n", i.u, i.v, i.w);
		// }
		return;
	}
	cop[x] = cop[x - 1], dfs(x + 1, sum);
	vector<edge> tmp;
	int i = 0, j = 0;
	for (int k=0; k<cop[x-1].size()+n; ++k) {
		if (j == n || (i < cop[x - 1].size() && cop[x - 1][i] < f[x][j])) tmp.push_back(cop[x - 1][i]), ++i;
		else tmp.push_back(f[x][j]), ++j;
	}
	cop[x] = kruskal(tmp), dfs(x + 1, sum + c[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> K;
//	cerr << n << " " << m << " " << K << "\n";
	for (int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		e.push_back((edge) {u, v, w});
	}
	sort(e.begin(), e.end());
	cop[0] = kruskal(e);
	for (int i=1; i<=K; ++i) {
		cin >> c[i];
		for (int j=1; j<=n; ++j) {
			int w; cin >> w;
			f[i].push_back((edge) {n + i, j, w});
		}
		sort(f[i].begin(), f[i].end());
	}
	dfs(1, 0);
	cout << ans << "\n";
	return 0;
}