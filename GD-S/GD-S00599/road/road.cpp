//无向连通图 
//最小生成树 
//当且仅当 城市之间互通的费用-乡镇通往城市的路的费用 之和 > 城市化费用时 城市化
//乡村之间不互通 
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f, M=1e4+15, O=0;
int n, m, k, ans, cnt, num;	//k<=10
int sum[15]; 
int fee[15][M];
int vis[M], a[M];
vector<pii> g[M];
void bfs(int x){	//O(m+kn)	2e6*log == 4e7
	priority_queue<pii, vector<pii>, greater<pii> > q;
	for (auto wv:g[x]) q.push(wv);
	vis[x]=1; cnt++;
	while (!q.empty()){
		if (cnt == num) return ;
		pii f=q.top(); q.pop(); 
		int u=f.second; if (vis[u]) continue; vis[u]=1; cnt++;
		ans+=f.first;
		for (auto wv:g[u]){
			if (vis[wv.second]) continue;
			q.push(wv);
		}
	}
	return ;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i=1; i<=n; i++) a[i]=INF;
	for (int i=1, u, v, w; i<=m; i++){
		scanf("%lld%lld%lld", &u, &v, &w);
		g[u].push_back({w, v});
		g[v].push_back({w, u});
		a[u]=min(a[u], w);
		a[v]=min(a[v], w);
	}
	num=n;
	for (int i=1; i<=k; i++){
		scanf("%lld", &fee[i][0]);
		for (int j=1; j<=n; j++){
			scanf("%lld", &fee[i][j]);
			sum[i]+=max(O, fee[i][j]-a[j]);
		} 
		if (sum[i] <= fee[i][0]) continue; num++;
//		ans+=fee[i][0]; 
		for (int j=1; j<=n; j++){
			g[n+i].push_back({fee[i][j], j});
			g[j].push_back({fee[i][j], n+i});
		}
	}	//init_g
	bfs(1); printf("%lld\n", ans);
	return 0;
}
