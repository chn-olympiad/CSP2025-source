#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int u,v,w;
};
struct node{
	int u,v,w;
	friend bool operator < (node a,node b){
		return a.w < b.w;
	}
}p[1000006];
vector<Node> G[2000006],g[2000006],e[2000006];
int	f[2000006],tot,n,m,u,v,w,Tot,ans = 1e18,otot,c[26],Ans,head[2000006],o[2000006],ttot,t[2000006],k,vis[26],Cnt,a[26][20006];
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
void kruskal(){
	sort(p+1,p+1+tot);
	for(int i = 1;i <= n; i++)
		f[i] = i;
	for(int i = 1;i <= m; i++){
		int u = p[i].u,v = p[i].v,w = p[i].w;
		int fx = find(u),fy = find(v);
		if(fx != fy){
			f[fx] = fy;
			g[w].push_back({u,v,w}); 
//			cout << u << " " << v << " " << w << endl;
		}
	}
}
void kruskal1(){
//	cout << "op" << Tot << endl;
	for(int i = 1;i <= n+Cnt; i++)
		f[i] = i;
	for(int i = 1;i <= Tot; i++){
//		cout << "L" << i << endl; 
		for(int j = 0;j < e[i].size(); j++){
			int u = e[i][j].u, v = e[i][j].v,w = e[i][j].w;
			int fx = find(u),fy = find(v);
//			cout << "()" << u << " " << v << endl;
			if(fx != fy){
				f[fx] = fy;
				Ans += o[w];
			}
		}
		for(int j = 0;j < G[head[i]].size(); j++){
			int u = G[head[i]][j].u, v = G[head[i]][j].v, w = G[head[i]][j].w;
			int fx = find(u),fy = find(v);
			if(fx != fy){
				f[fx] = fy;
				Ans += o[w];
			}
		}
	}
//	int o = find(1);
//	bool r = 1;
//	for(int i = 1;i <= n+Cnt; i++)
//		if(find(i) != o)
}
void dfs(int x){
	if(x == k+1){
		Cnt = Ans = 0; 
		for(int i = 1;i <= ttot; i++)
			G[t[i]].clear();
		for(int i = 1;i <= k; i++){
			if(vis[i]){
				Cnt++;
				for(int j = 1;j <= n; j++)
					G[a[i][j]].push_back({n+Cnt,j,a[i][j]});
				Ans += c[i];
			}
		}
		kruskal1();
		ans = min(ans,Ans);
		return ;
	}
	dfs(x+1);
	vis[x] = 1;
	dfs(x+1);
	vis[x] = 0;
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m; i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		p[++tot] = {u,v,w};
		o[++otot] = w;
	}
	sort(p+1,p+1+tot);
	bool flag1 = 1;
	for(int i = 1;i <= k; i++){
		cin >> c[i];
		for(int j = 1;j <= n; j++){ 
			scanf("%lld",&a[i][j]);
			o[++otot] = a[i][j];
			t[++ttot] = a[i][j];
		} 
	}
	sort(o+1,o+1+otot);
	otot = unique(o+1,o+1+otot)-(o+1);
	sort(t+1,t+1+ttot);
	ttot = unique(t+1,t+1+ttot)-(t+1);
//	for(int i = 1;i <= otot; i++)
//		cout << o[i] << " ";
//	cout << endl;
	for(int i = 1;i <= k; i++)
		for(int j = 1;j <= n; j++)
			a[i][j] = lower_bound(o+1,o+1+otot,a[i][j])-o,vis[a[i][j]] = 1;
	for(int i = 1;i <= ttot; i++)
		t[i] = lower_bound(o+1,o+1+otot,t[i])-o;
	for(int i = 1;i <= tot; i++)
		p[i].w = lower_bound(o+1,o+1+otot,p[i].w)-o;
	kruskal(); 
	vis[0] = 1;
	for(int i = 1;i <= otot; i++){
		if(vis[i])
			head[++Tot] = i;
		if(!vis[i]&&vis[i-1])
			head[++Tot] = i;
		for(int j = 0;j < g[i].size(); j++)
			e[Tot].push_back(g[i][j]);
	}
//	for(int i = 1;i <= Tot; i++)
//		cout << head[i] << endl;
//	cout << "#" << Tot << endl;
	dfs(1);
	cout << ans << endl;
	return 0;
}
