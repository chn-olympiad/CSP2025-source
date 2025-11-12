# include <bits/stdc++.h>
# define pb push_back
# define int long long
using namespace std;

const int N = 1e4 + 15, M = 1e6 + 5;

int read(){
	int ret = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') ret = ret*10 + (c-'0'), c = getchar();
	return ret;
}

int n, m, k, cnt = 0, tmp = 0, CNT = 0, ans = 0, fa[N], c[15];

int fnd(int x){return x == fa[x] ? x : fa[x] = fnd(fa[x]);}

struct node{
	int u, v, w, id;
} edge[M], dt[15][N], EDGE[M];

bool cmp(node a, node b){return a.w < b.w;}

signed main(){
	freopen("road.in",  "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road3.in", "r", stdin);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1, u, v, w;i <= m;i++){
		u = read(); v = read(); w = read();
//		scanf("%lld%lld%lld", &u, &v, &w);
		edge[++cnt] = (node){u, v, w, 0};
	}
	for (int i = 1, x;i <= k;i++){
		scanf("%lld", &c[i]);
		for (int j = 1;j <= n;j++){
			scanf("%lld", &x);
			dt[i][j] = (node){i+n, j, x, i};
		}
	}
	sort (edge+1, edge+m+1, cmp);
	for (int i = 1;i <= n;i++) fa[i] = i;// tmp = m;
	for (int i = 1;i <= m;i++){
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if (fnd(u) == fnd(v)) continue;
		fa[fnd(u)] = fa[fnd(v)]; ans += w;
		swap(edge[i], edge[++tmp]);
	} 
	for (int i = 1;i < (1 << k);i++){
		CNT = 0;
		int res = 0, p = 0;
		for (int j = 1;j <= k;j++) if (i & (1ll << (j-1))){
			for (int o = 1;o <= n;o++) EDGE[++CNT] = dt[j][o];
			res += c[j];
		}
		for (int j = 1;j <= tmp;j++) EDGE[++CNT] = edge[j];
		for (int j = 1;j <= n+k;j++) fa[j] = j;
		sort(EDGE+1, EDGE+CNT+1, cmp);
		for (int j = 1;j <= CNT;j++){
			int u = EDGE[j].u, v = EDGE[j].v, w = EDGE[j].w;
			if (fnd(u) == fnd(v)) continue;
			fa[fnd(u)] = fnd(v); p++;
			res += w;
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}

