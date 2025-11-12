#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
vector<PII> g[10020];
int dis[10020],vis[10020],c[20],frr[20],fr[20];
priority_queue<pair<int,PII>,vector<pair<int,PII>>,
greater<pair<int,PII>> > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0,cnt=0;
	cin>>n>>m>>k;
	for(int i = 1,u,v,w;i <= m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		if(u==1||v==1)cnt++;
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1,w;j <= n;j++){
			cin>>w;
			g[j].push_back({n+i,c[i]+w});
			g[n+i].push_back({j,w});
		}
	}
	//Prim
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push({0,{1,0}});
	while(!q.empty()){
		int u = q.top().second.first;
		if(vis[u]){
			q.pop();
			continue;
		}
		vis[u]=1;
		ans+=q.top().second.second;
		q.pop();
		for(auto t:g[u]){
			int v = t.first,w = t.second;
			if(!vis[v] && w < dis[v]){
				if(!vis[v]){
					if(u>n) fr[u-n]++,frr[v]=u-n;
					else if(frr[v]) fr[frr[v]]--,frr[v]=0;
				}
				dis[v] = w;
				q.push({dis[v],{v,w}});
			}
		}
	}
	for(int i = 1;i <= k;i++) if(fr[i]==0) ans-=c[i];
	cout<<ans;
	return 0;
}