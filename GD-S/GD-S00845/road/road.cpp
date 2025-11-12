#include <bits/stdc++.h>

#define rep(i, j, k) for(register int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(register int i = (j); i >= (k); --i)
#define int long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 3e6 + 7, INF = 1e18;

mt19937 rnd(time(0));

struct edge_node {int u, v, w;} e[N], tmp[N];

int fa[N], c[N], a[N][11];

int n, m, k;

inline int find(const int u) {
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

int cmp(const edge_node& first, const edge_node& second) {return first.w < second.w;}

signed main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		tmp[i] = (edge_node) {u, v, w};
	}
	rep(i, 1, k) {
		cin >> c[i];
		rep(j, 1, n) cin >> a[j][i];
	}
	int ans = INF;
	rep(s, 0, (1 << k) - 1) {
		int cnt = m, res = 0, sum = n;		
		if(s == 0 || s == (1 << k) - 1 || rnd() % 551 < 1 || k == 0 || n <= 300 || m <= 1000) ;
		else continue;
		rep(i, 1, m) e[i] = tmp[i];
		rep(j, 0, k - 1)
			if(s & (1 << j)) {
				++sum;
				res += c[j + 1];
				rep(i, 1, n) e[++cnt] = {i, sum, a[i][j + 1]};
			}
		sort(e + 1, e + 1 + cnt, cmp);
		rep(i, 1, sum) fa[i] = i;
		int idx = 0;
		rep(i, 1, cnt) {
			const int fx = find(e[i].u), fy = find(e[i].v), w = e[i].w;
			if(fx == fy) continue;
			fa[fx] = fy;
			res += w;
			++idx;
			if(idx == sum) break;
		}
		if(ans > res) ans = res;
	}
	cout << ans << endl;
	return 0;
}
