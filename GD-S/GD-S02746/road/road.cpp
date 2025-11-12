#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int N = 2e4 + 5;

int n, m, k;
int fa[N], sz[N];
void init(int nn) {
	for (int i = 1; i <= nn; i++)
		fa[i] = i, sz[i] = 1;
}
int fnd(int x) {
	return fa[x] == x ? x : fa[x] = fnd(fa[x]);
}
void unn(int x, int y) {
	x = fnd(x), y = fnd(y);
	if (x == y)	
		return ;
	if (sz[x] > sz[y])
		swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
}
struct Edge {
	int u, v, w;
	Edge(){}
	Edge(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
};
bool operator<(Edge x, Edge y) {
	return x.w < y.w;
}
vector<Edge> edg;
vector<Edge> v2;

int c[15], a[11][N];
ll s[1 << 10];

void slv() {
	cin >> n >> m >> k;
	vector<Edge>().swap(edg);
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		edg.emplace_back(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	init(n);
	sort(edg.begin(), edg.end());
	vector<Edge>().swap(v2);
	
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		if (fnd(edg[i].u) != fnd(edg[i].v)) {
			ans += edg[i].w;
			v2.push_back(edg[i]);
			unn(edg[i].u, edg[i].v);
		}
	}
	
	swap(edg, v2);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++)
			edg.emplace_back(j, i + n, a[i][j]);
	}
	sort(edg.begin(), edg.end());
	
	s[0] = 0;
	for (int i = 1; i < (1 << k); i++) {
		s[i] = s[i - (i & -i)] + c[__lg(i & -i) + 1];
		if (s[i] >= ans)
			continue;
		init(n + k);
		ll res = 0;
		for (int j = 0; j < edg.size(); j++) {
			if (edg[j].v > n && !((i >> (edg[j].v - n - 1)) & 1))
				continue;
			if (fnd(edg[j].u) != fnd(edg[j].v)) {
				res += edg[j].w;
				unn(edg[j].u, edg[j].v);
			}
		}
		ans = min(ans, res + s[i]);
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("1.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--)
		slv();
	return 0;
}
