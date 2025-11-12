#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
long long a[20][maxn];
int n,m,k;
vector<pair<int,int>> g[maxn];
long long c[maxn];
int fa[maxn];
int get(int u) {
	if (fa[u] == u) return u;
	return fa[u] = get(fa[u]);
}
void add(int u,int v) {
	u = get(u),v = get(v);
	if (u != v) {
		fa[u] = v;
	}
	return ;
}
struct jkl{
	long long u,v,w;
}edge[maxn];
int tot = 0;
long long ans = 0;
bool cmp(jkl x,jkl y) {
		return x.w < y.w;
	}
void solve() {
	sort(edge + 1, edge + 1 + tot,cmp);
	//cout << tot << endl;
	//for (int i = 1; i <= tot; i++) cout << edge[i].u << " " << edge[i].v << " " <<edge[i].w << endl;
	
	for (int i = 1; i <= tot; i++) {
		int u = get(edge[i].u);
		int v = get(edge[i].v);
		//int u = 0,v = 0;
		
	//	if (edge[i].w == 1) cout << u << " " <<  v << << endl;
		if (u == v) continue;
		fa[u] = v;
		ans += edge[i].w;	
		
	}
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		edge[++tot] = (jkl){u,v,w};
		//edge[++tot] = (jkl){v,u,w};
 }
 
 if (k == 0) {
	// cout << "jlksdf";
	solve();
 } else {
 for (int i = 1; i <= k; i++) {
	scanf("%lld",&c[i]);
	//if (c[i] == 0) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld",&a[i][j]);
			if (a[i][j] == 0) {
				add(i + n,j);
			//	cout << i + n << " " << j << endl;
			} else {
				g[i + n].push_back({j,a[i][j]});
				g[j].push_back({i + n,a[i][j]});
				edge[++tot] = (jkl){j,i + n,a[i][j]};
				//edge[++tot] = (jkl){i + n,j,a[i][j]};
				
			}
		}
		
	//}
 }
 solve();
}
	cout << ans << endl;
	 return 0;
}
