#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005,M=1000005,inf=1e16;
int n,m,k,a[N],f[N],g[1005][1005],h[1005][1005],dis[1005],d[1005],vis[1005],c[15][N];
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool check(){
	for(int i=1;i<=k;i++)if(a[i])return 0;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++)f[i]=i;
		int ans=0;
		for(int i=1;i<=m;i++){
			int U=find(e[i].u),V=find(e[i].v);
			if(U!=V)f[U]=V,ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)g[i][j]=g[j][i]=inf;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	if(check()){
		int ans=inf,s=(1<<k)-1;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)h[i][j]=g[i][j];
		int sum=0;
		for(int i=1;i<=k;i++)if(s>>(i-1)&1){
			sum+=a[i];
			for(int u=1;u<=n;u++)for(int v=1;v<=n;v++)h[u][v]=h[v][u]=min(h[u][v],c[i][u]+c[i][v]);
		}
		for(int i=0;i<=n;i++)dis[i]=inf,vis[i]=0;
		dis[1]=0,vis[1]=1;
		for(int i=1;i<=n;i++)dis[i]=h[1][i];
		for(int i=1;i<n;i++){
			int u=0;
			for(int j=1;j<=n;j++)if(!vis[j]&&dis[j]<=dis[u])u=j;
			sum+=dis[u],dis[u]=0,vis[u]=1;
			for(int j=1;j<=n;j++)dis[j]=min(dis[j],h[u][j]);
		}
		ans=min(ans,sum);
		cout<<ans;
		return 0;
	}
	int ans=inf;
	for(int s=0;s<1<<k;s++){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)h[i][j]=g[i][j];
		int sum=0;
		for(int i=1;i<=k;i++)if(s>>(i-1)&1){
			sum+=a[i];
			for(int u=1;u<=n;u++)for(int v=1;v<=n;v++)h[u][v]=h[v][u]=min(h[u][v],c[i][u]+c[i][v]);
		}
		for(int i=0;i<=n;i++)dis[i]=inf,vis[i]=0;
		dis[1]=0,vis[1]=1;
		for(int i=1;i<=n;i++)dis[i]=h[1][i];
		for(int i=1;i<n;i++){
			int u=0;
			for(int j=1;j<=n;j++)if(!vis[j]&&dis[j]<=dis[u])u=j;
			sum+=dis[u],dis[u]=0,vis[u]=1;
			for(int j=1;j<=n;j++)dis[j]=min(dis[j],h[u][j]);
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}
