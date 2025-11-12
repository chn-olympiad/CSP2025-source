#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e4 + 5, M = 2e6 + 5, INF = 1e18;
int n, m, k, tot, totc, ans;
struct edge{int u, v, w;} e[M], x[M], ec[M];
int c[N], fa[N];

inline void init() {for(int i = 1; i <= n + k; ++i) fa[i] = i;}
inline int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
inline bool cmp(edge A, edge B) {return A.w < B.w;}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + 1 + m, cmp);
	init();
	for(int i = 1; i <= m; ++i){
		int fu = find(e[i].u), fv = find(e[i].v);
		if(fu ^ fv) e[++tot] = e[i], fa[fu] = fv;
	}
	for(int i = 0; i < k; ++i){
		scanf("%lld", &c[i]);
		for(int j = 1, awa; j <= n; ++j){
			scanf("%lld", &awa);
			ec[++totc] = {i, j, awa};
		}
	}
	sort(ec + 1, ec + 1 + totc, cmp);
	ans = INF;
	for(int S = 0; S < 1 << k; ++S){
		int res = 0;
		for(int i = 0; i < k; ++i) if((S >> i) & 1) res += c[i];
		int i = 1, j = 1;
		init();
		while(i <= tot || j <= totc){
			bool ok = false;
			if(j <= totc){
				ok = ((S >> ec[j].u) & 1);
				if(!ok) {++j; continue;}
			}
			if(i <= tot && (j > totc || ec[j].w >= e[i].w)){  
				int fu = find(e[i].u), fv = find(e[i].v);
				if(fu ^ fv) fa[fu] = fv, res += e[i].w;
				++i;	
			}
			else if(j <= totc && ec[j].w < e[i].w){
				int fu = find(ec[j].u + 1 + n), fv = find(ec[j].v);
				if(fu ^ fv) fa[fu] = fv, res += ec[j].w;
				++j;
			}
			else break;
			if(res > ans) break;
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}
