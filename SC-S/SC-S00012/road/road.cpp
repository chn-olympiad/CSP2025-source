#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+50,M=1e6+10;
int n,m,k,ans=1e9,cnt;
struct edge{
	int u,v,w;
}e[M];
vector<edge> g[N];
map<int,map<int,int> >vis,mp;
int c[N],d[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	return fa[x]= fa[x]==x?x:find(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vis[u][v]=vis[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(!vis[u][v]) vis[u][v]=vis[v][u]=mp[i][u]+mp[i][v];
				else vis[u][v]=vis[v][u]=min(vis[u][v],mp[i][u]+mp[i][v]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			e[++cnt]={i,j,vis[i][j]};
		}
	sort(e+1,e+cnt+1,cmp);
	int num=1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		if(num==n) break;
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			fa[find(e[i].v)]=find(e[i].u);
			num++;
		}
	}
	cout<<ans;
}