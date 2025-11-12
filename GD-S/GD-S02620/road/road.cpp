#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5,K = 11,INF = 1e18 + 7;

int n,m,k,num;
int ed[N],sum[K];
struct node{int u,v,w;}e[M],us[N];
int a[K][N];
bool cmp(node x,node y){return x.w < y.w;}
int ans = INF;
int dot[K],tot;
namespace DSU{
	int fa[N + K];
	inline int find(int x){return ((fa[x] == x) ? (fa[x]) : (fa[x] = find(fa[x])));}
	inline bool merge(int x,int y){x = find(x);y = find(y);if (x == y) return false;fa[x] = y;return true;}
}using namespace DSU;
void kruskal(int flag,int st){
	if (flag){
		num = n - 1;
		for (int i = 1;i < n;i++) e[i] = us[i];
		for (int i = 1;i <= tot;i++){
			for (int j = 1;j <= n;j++) 
			if (a[dot[i]][j] < us[n - 1].w) e[++num] = {n + dot[i],j,a[dot[i]][j]};
		}
	}else num = m;
	for (int i = 1;i <= n + k;i++) fa[i] = i;
	stable_sort(e + 1,e + 1 + num,cmp);
	int ecnt = 0,sumt = 0;
	for (int i = 1;i <= num;i++){
		if (ecnt == n + tot - 1) break;
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if (merge(u,v)){
			sumt += w;ecnt++;
			if (!flag) us[ecnt] = {u,v,w};
		}
	}
	ans = min(ans,sumt + st);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1;i <= k;i++){
		cin >> sum[i];
		for (int j = 1;j <= n;j++) cin >> a[i][j];
	}kruskal(0,0);
	for (int s = 0;s < (1 << k);s++){
		tot = 0;int st = 0;
		for (int i = 0;i < k;i++) if ((s >> i) & 1) dot[++tot] = i + 1,st += sum[i + 1];
		kruskal(1,st);
	}cout << ans << "\n";
	return 0;
}
