#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(p) freopen(#p".in","r",stdin),freopen(#p".out","w",stdout);
#define pii pair<int,int>
const int maxn=10001;
const int maxm=11;
ll MAXX=4e18;
bool vis[maxn]={0};
int dis[maxn];
int n,m,k;
vector<vector<pii>>adj(maxn);
int c[maxm],d[maxm][maxn],e[maxm];
int main(){
	memset(dis,0x3f,sizeof(dis));
	memset(e,0x3f,sizeof(e));
	fre(road);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			int a;
			scanf("%d",&a);
			d[i][j]=a;
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1}); 
	while(!pq.empty()){
		int current_v=pq.top().first;
		int current_node=pq.top().second;
		vis[current_v]=1;
		pq.pop();
		if(current_v>=dis[current_node])continue;
		dis[current_node]=min(current_v,dis[current_node]);
		for(int i=0;i<adj[current_node].size();++i){
			if(vis[adj[current_node][i].first]==0)pq.push({adj[current_node][i].second,adj[current_node][i].first});
		}
	}
	ll MINN=0;
	for(int i=1;i<=n;++i){
		MINN+=dis[i];
	}
	for(int i=1;i<=k;++i){
		ll T=MINN+c[i];
		int cnt=0;
		bool ad[maxn]={0};
		for(int j=1;j<=n;++j){
			if(d[i][j]>=dis[i]){
				cnt++;
				ad[j]=1;
				T=T+d[i][j]-dis[i];
			}
		}
		if(cnt>=2||cnt==0)MINN=min(MINN,T);
		else {
				int MI=1e9;
				for(int j=1;j<=n;j++){
					if(ad[j]==0)MI=min(MI,d[i][j]-dis[i]);
				}
				MINN=min(MINN,T+MI);
		}
	}
	cout<<MINN;
	return 0;
}

