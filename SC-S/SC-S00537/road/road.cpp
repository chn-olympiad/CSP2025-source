#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4 + 20, maxm = 1e6 + 10, maxk = 15; const ll inff = 2e18;
int n, m, k, c[maxk], a[maxk][maxn];
ll ans, res;

struct edge{int u, v, w;} e0[maxm << 1], e[maxm << 1];
inline bool cmp(edge x, edge y) {return x.w < y.w;}

int fa[maxn];
inline int fd(int u) {return u == fa[u] ? u : fa[u] = fd(fa[u]);}

int tot0, tot;
void init() {
	res = 0;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	sort(e + 1, e + tot + 1, cmp);
}
ll kruskal() {
	init();	
	for(int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v;
		int fu = fd(u), fv = fd(v);
		if(fu != fv) {
			fa[fu] = fv;
			res += e[i].w;
		}
	} return res;
}

bool typA = true;
void subA() {
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) e[++tot] = (edge){n + i, j, a[i][j]};
	} cout << kruskal();
}

int main() {
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w; e[i] = e0[i] = (edge){u, v, w};
	} tot = tot0 = m;
	
	ans = kruskal();
	for(int i = 1; i <= k; i++) {
		cin >> c[i]; typA &= c[i] == 0;
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if(typA) subA(), exit(0);
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= tot; j++) e[j] = e0[j]; tot = tot0;
		
		for(int j = 1; j <= n; j++) e[++tot] = (edge){n + i, j, a[i][j]};
		
		ll tmp = kruskal();
		if(tmp + c[i] <= ans) {
			for(int j = 1; j <= tot; j++) e0[j] = e[j]; tot0 = tot;
			ans = tmp + c[i];
		}
	} cout << ans;
	
	return 0;
}
// why kachang?
// how prim?