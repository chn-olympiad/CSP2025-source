#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+5;
int n,m,k;
int c[N],d[15][N];
int dis[N][N],dis1[N][N];
int dt[N],vis[N];
int prim(){
	memset(dt,0x3f,sizeof(dt));
	memset(vis,0,sizeof(vis));
	dt[1] = 0;dis[0][1] = 0;
	int sum = 0;
	while(1){
		int u = 0;
		for(int j=1;j<=n;++j){
			if(dt[u]>dt[j] and !vis[j]){
				u = j;
			}
		}
		if(!u) break;
		sum+=dt[u];
		vis[u] = 1;
//		cout<<u<<"\n";
		for(int j=1;j<=n;++j){
			dt[j] = min(dt[j],dis[u][j]);
		}
	}
	return sum;
}
struct node{
	int w,u,v;
};
vector<node> G;
bool cmp(node b,node c){
	return b.w<c.w;
}
int f[N*10];
int find(int x){
	if(f[x]==x) return x;
	return f[x] = find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=n;++i) f[i] = i;
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin>>u>>v>>w;
			G.push_back({w,u,v});
		}
		int ans = 0;
		sort(G.begin(),G.end(),cmp);
		for(int i=0;i<G.size();++i){
			int u = G[i].u,v = G[i].v,w = G[i].w;
			int fu = find(u),fv = find(v);
			if(fu==fv) continue;
			f[fu] = fv;
			ans+=w;
		}
		cout<<ans;
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v] = w;
		dis[v][u] = w;
		dis1[u][v] = dis[u][v];
		dis1[v][u] = dis[v][u];
	}	
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>d[i][j];
		}
	}
	int sum = 1e18;
	for(int i=1;i<(1<<(k));++i){
		auto b = bitset<10>(i);
		vector<int> p;
		for(int j=0;j<k;++j){
			if(b[j]) p.push_back(j+1);
		}
		int ans = 0;
		for(int v:p){
			for(int k=1;k<=n;++k){
				for(int t=k+1;t<=n;++t){
					dis[k][t] = min(dis[k][t],d[v][k]+d[v][t]);
					dis[t][k] = dis[k][t];
				}
			}
			ans+=c[v];
		}
		sum = min(sum,ans+prim());
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				dis[i][j] = dis1[i][j];
			}
		}
	}
	cout<<sum;
//	cout<<prim();
}