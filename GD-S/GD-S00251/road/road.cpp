#include<bits/stdc++.h>
using namespace std;
int mp[10011][10011],sum[10011];
int k[14][10011];
bool vis[100010];
struct aaaa{
	int uuu,yyy;
}xxx[1000010],dis[100010];
int n,m,K;
int yui=0;
int prim(){
	memset(vis,0,sizeof(vis));
	int s=1;
	int toot=0;
	vis[s]=1;
	for(int i=1;i<=n;i++){
		dis[i].uuu=mp[s][i];
	}
	for(int i=1;i<n;i++){
		int mi=2000000000,kk;
		for(int j=1;j<=n;j++){
			if(dis[i].uuu<mi&&!vis[i]){
				mi=dis[i].uuu;
				kk=j;
			}
		}
		vis[kk]=1;
		xxx[++yui].uuu=kk,xxx[yui].yyy=dis[kk].yyy;
		toot+=dis[kk].uuu;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(dis[kk].uuu+mp[kk][i]<dis[i].uuu){
					dis[i].uuu=dis[kk].uuu+mp[kk][i];
					dis[i].yyy=i;
				}
				
				
			}
		}
	}
	return toot;
}
int main(){
	memset(mp,2000000000,sizeof(mp));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	for(int i=1;i<=K;i++){
		cin>>sum[i];
		for(int j=1;j<=n;j++){
			cin>>k[i][j];
		}
	}
	int ans=prim();
	for(int i=1;i<=K;i++){
		int sumx=-sum[i];
		for(int j=1;j<=yui;j++){
			sumx+=(mp[xxx[j].uuu][xxx[j].yyy]-k[i][xxx[j].uuu]-k[i][xxx[j].yyy]);
		}
		if(sumx>0){
			ans-=sumx;
		}
	}
	cout<<ans;
	return 0;
} 
