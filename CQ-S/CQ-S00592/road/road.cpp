#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10, inf=1e9+10, M=1e4+10;
int n, m, k;
int to[N], v[N], nex[N], h[N], f[N];
int cnt;
int a[15][M];
int dis[N];
bool vis[N];
int ans;
int w[N];
int x=1e9+10;
int e;
void add(int a, int b, int c)
{
	to[++cnt]=b;
	f[cnt]=a;
	v[cnt]=c;
	nex[cnt]=h[a];
	h[a]=cnt;
}
void ff()
{
	for(int i=1; i<=cnt; i++){
		for(int j=1; j<=k; j++){
			if(v[i]>a[j][f[i]]+a[j][to[i]]+w[i])
				v[i]=a[j][f[i]]+a[j][to[i]]+w[i]; 
		}
	}
}
void work(){
	for(int i=1; i<=n; i++)
		dis[i]=inf;
	dis[1]=0, dis[0]=inf;
	while(true){
		int u=0;
		for(int i=1; i<=n; i++)
			if(vis[i]==0 && dis[u]>dis[i])
				u=i;
		if(u==0) break;
		vis[u]=1;
		ans+=dis[u];
		for(int i=h[u]; i; i=nex[i])
			if(dis[to[i]]>v[i])
				dis[to[i]]=v[i];
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=1; i<=k; i++){
		cin>>w[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	ff();
	work();
	cout<<ans;
	return 0;
}
