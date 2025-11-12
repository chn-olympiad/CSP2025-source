#include<bits/stdc++.h>
using namespace std;

int n,m,k,head[11451],tot=0,c[15],ans=0;

bool vis[11451];

struct node{
	int d,t;
}dist[11451];

struct edge{
	int nxt,to,w;
}e[2114514];

void awa(int u,int v,int w)
{
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void dij(int s)
{
	c[0]=0;
	for(int i=1;i<=n+k;i++) vis[i]=0,dist[i].d=999999999,dist[i].t=0;
	dist[s].d=0;
	for(int i=1;i<n+k;i++){
		int minn=999999999,p=0;
		for(int j=1;j<=n+k;j++){
			if(j<=n){
				if(dist[j].d+dist[j].t<minn&&!vis[j]){
					p=j;
					minn=dist[j].d+dist[j].t;
				}
			}
			else{
				if(dist[j].d+dist[j].t+c[j-n]<minn&&!vis[j]){
					p=j;
					minn=dist[j].d+dist[j].t+c[j-n];
				}
			}
		}
		vis[p]=1;
		for(int j=head[p];j;j=e[j].nxt){
			int v=e[j].to,w=e[j].w;
			if(p<=n){
				if(dist[v].d+dist[v].t>dist[p].d+w+dist[p].t&&!vis[v]){
					dist[v].d=dist[p].d+w;
					dist[v].t=dist[p].t;
				}
			}
			else{
				if(dist[v].d+dist[v].t>dist[p].d+dist[p].t+w+c[p-n]&&!vis[v]){
					dist[v].d=dist[p].d+w;
					dist[v].t=dist[p].t+c[p-n];
				}
			}
		}
	}
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		awa(u,v,w);
		awa(v,u,w);
	}
	for(int u=n+1;u<=n+k;u++){
		cin >> c[u-n];
		for(int v=1;v<=n;v++){
			int w;
			cin >> w;
			awa(u,v,w);
			awa(v,u,w+c[u-n]);
		}
	}
	dij(1);
	for(int i=1;i<=n+k;i++){
		if(vis[i]){
			if(i<=n) ans=max(ans,dist[i].d+dist[i].t);
			else ans=max(ans,dist[i].d+dist[i].t+c[i-n]);
		}
	}
	cout << ans+2;
	return 0;
} 
