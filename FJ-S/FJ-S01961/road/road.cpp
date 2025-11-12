#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;

int n,m,k;
ll g[N][N];

int c[15];
int w[15][N];

ll dis[N],vis[N];

ll p(){
	memset(dis,0x3f,sizeof dis);
	
	dis[1]=0;
	ll res=0;
	for(int j=1;j<=n;j++)
	{
		int u=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&& (u==-1 || dis[i]<dis[u]))
				u=i;
		
		vis[u]=1;
		res+=dis[u];
				
		for(int v=1;v<=n;v++)
			if(!vis[v])
				dis[v]=min(dis[v],g[u][v]);
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(g,0x3f,sizeof g);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	}
	
	for(int i=1;i<=k;i++)
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				g[v][u]=g[u][v]=min(g[u][v],(ll)c[i]+w[i][u]+w[i][v]);
	
	cout<<p()<<endl;
	return 0;
}
