#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y;i++)
#define per(i,x,y) for(int i = x; i >= y; i--)
#define int long long
using namespace std;

const int MAXN = 1e4 + 5, MAXM = 1e6 +5, MAXK = 11;

int n, m, k;
struct node {
	int u, v, w;
} g[MAXM<<1], g2[MAXM<<1];

int tot;

int ans, res;

int fa[MAXN];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool debug;

bool cmp(node x, node y) {
	return x.w < y.w;
}

void kruskal() {
	rep(i, 1, tot) g2[i] =g[i];
	rep(i, 1, n + k) fa[i] = i, res = 0;
	sort(g2 + 1, g2 + 1 + tot, cmp);
	rep(i, 1, tot) {
		
		int u = g2[i].u, v = g2[i].v, w = g2[i].w;
//		if(debug) cerr << u << ' ' << v << ' ' << w << '\n';
		if(find(u) == find(v)) continue;
		fa[find(u)] = find(v);
		res += w;
	
	}
}
int C[MAXN], W[MAXK][MAXN];

signed main() {
//	freopen(".in", "r", stdin);
//	freopen("std.out", "w", stdout);
	freopen("road3.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >>w;
		g[++tot] = {u, v, w};
	}

	rep(i, 1, k) {
		cin >>C[i];
		rep(j, 1, n) cin >>W[i][j];
	}
	kruskal(), ans = res;
	
	for(int S = 0; S < (1 << k); S++) {
		
		int lst = tot, sum = 0;
		for(int i = 0; i < k; i++) {
			if(S>> i &1) {
				sum += C[i + 1];
				rep(j, 1, n) g[++tot] = {n + i + 1, j, W[i + 1][j]};
			}
		}
		kruskal();
		ans= min(ans, res + sum);
		tot = lst;
	}
	cout << ans;
	return 0;
}

