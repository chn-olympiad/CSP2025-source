#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = 10015, M = 1000005, K = 10;
int n, m, mm, k;ll ans, f[1 << K];
struct Edge{int u, v, w;}E[M], F[M];
struct DSU{int fa[N], sz[N];
	void init(){for (int i = 1;i <= n + k;i ++) fa[i] = i, sz[i] = 1;}
	inline int getfa(int x){return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
	inline bool merge(int x, int y){
		if ((x = getfa(x)) == (y = getfa(y))) return 0;
		if (sz[x] < sz[y]) swap(x, y);fa[y] = x, sz[x] += sz[y];return 1;
	}
}st[1 << K], sr;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k, sr.init(), ans = 1000000000000000000;
	for (int i = 1;i <= m;i ++) cin >> E[i].u >> E[i].v >> E[i].w;
	sort(E + 1, E + m + 1, [&](Edge a, Edge b){return a.w < b.w;});
	for (int i = 1;i <= m;i ++) if (sr.merge(E[i].u, E[i].v)) F[++ mm] = E[i];
	for (int i = 0, w;i < k;i ++){cin >> w;
		for (int s = 0;s < 1 << k;s ++) if (s >> i & 1) f[s] += w;
		for (int j = 1;j <= n;j ++) cin >> w, F[++ mm] = {j, i + n + 1, w};
	}sort(F + 1, F + mm + 1, [&](Edge a, Edge b){return a.w < b.w;});
	for (int s = 0;s < 1 << k;s ++) st[s].init();
	for (int i = 1;i <= mm;i ++)
	for (int s = 0;s < 1 << k;s ++)
	if (F[i].v <= n || (s >> F[i].v - n - 1 & 1))
	if (st[s].merge(F[i].u, F[i].v)) f[s] += F[i].w;
	for (int s = 0;s < 1 << k;s ++) ans = min(ans, f[s]);cout << ans;
}