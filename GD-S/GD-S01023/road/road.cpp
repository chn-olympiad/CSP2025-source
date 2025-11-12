#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,k,w[100005][15],c[15],dis[100005],vis[100005];
vector<pair<int,int> > v[10005];
void dijkstra(){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue<pair<int,int> > q;
	q.push({-dis[1],1});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<v[u].size();i++){
			int x=v[u][i].second;
			if(dis[x]>dis[u]+v[u][i].first){
				dis[x]=dis[u]+v[u][i].first;
				q.push({-dis[x],x});
			}
		}
	}
}
signed main(){
	IOS
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({w,y});
		v[y].push_back({w,x});
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>w[i][j];
	}
	if(k==0){
		dijkstra();
		cout<<dis[n]<<endl;
	}
	return 0;
}

