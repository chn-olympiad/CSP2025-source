#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y;i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
using namespace std;

const int MAXN = 3e4 + 5, MAXM = 2e6 +5, MAXK = 15;

int n, m, k;
struct node {
	int u, v, w;
} g[MAXM<<1];

int tot;
int ans, res;
bool debug;
int fa[MAXN],sz[MAXN];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v) {
	if(sz[u] > sz[v]) swap(u, v);
	fa[u] = v, sz[v] += sz[u];
}

bool cmp(node x, node y) {
	return x.w < y.w;
}
bool del[MAXN];
void kruskal() {
	rep(i, 1, n + k) fa[i] = i, sz[i] = 1;
	res = 0;
	rep(i, 1, tot) {
		if(del[g[i].u] || del[g[i].v]) continue;
		int u = find(g[i].u), v = find(g[i].v), w = g[i].w;
		if(u == v) continue;
		merge(u, v), res += w;
	}
}
int C[MAXN], W[MAXK][MAXN];

signed main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	bool flag = 1;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >>w;
		g[++tot] = {u, v, w};
		
	}
	rep(i, 1, k) {
		cin >> C[i];
		bool flag2 = 0;
		
		
		rep(j, 1, n) cin >>W[i][j], g[++tot] = {n + i, j, W[i][j]}, flag2
		 |= W[i][j] == 0;
		flag &= (g && C[i] == 0);
	}
	sort(g + 1, g + 1 + tot, cmp);
	if(flag){
		kruskal();
		cout <<res;
		return 0;
	}
	int ans = 1e18;
	for(int S = 0; S < (1 << k); S++) {
		int sum = 0;
		rep(i, 1, k) del[n + i] = 1;
		rep(i, 1, k) if(S >> (i - 1) & 1)	{
			del[n + i] = 0, sum += C[i];
		}
		kruskal();
		ans = min(ans, res + sum);
	}
	cout << ans;
	return 0;
}
