#include<bits/stdc++.h>
using namespace std;
int to[10005],h[10005],nxt[10005];
int val[10005];
int dis[100005];
int cnt;
int n,m,k;
bool vis[100006];
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
int dij(){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}
	dis[0]=1e9;
	dis[1]=0;
	int u;
	while(true){
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]>dis[1]){
				u=i;
			}
		}
		if(u==0){
			break;
		}
		vis[u]=true;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[to[i]]>dis[u]+val[i]){
				dis[to[i]]=dis[u]+val[i];
			}
		}
		
	}
	
	return dis[n];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	cout<<dij();
	return 0;
}
