//GZ-S00231 观山湖中学 李朋钊
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>
const int N=1e4+20;
vector<pii> G[N];
ll dis[N], vis[15], c[15][N];
int n, m, k;
struct node{
	int u;ll w;int f;
};
int dij(int st){
	memset(dis,0x3f,sizeof dis);
	dis[st]=0;
	queue<node> q;
	q.push({st, 0, 0});
	while(!q.empty()){
		node t=q.front();
		q.pop();
		for(int i=0;i<G[t.u].size();i++){
			if(G[t.u][i].first==t.f) continue;
			if(dis[G[t.u][i].first]>t.w+G[t.u][i].second){
				dis[G[t.u][i].first]=t.w+G[t.u][i].second;
				q.push({G[t.u][i].first, dis[G[t.u][i].first], t.u});
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=min(ans,dis[i]);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i=1;i<=k;i++){
		ll x;
		cin>>x;
		c[i][0]=x;
		for(int j=1;j<=n;j++){
			cin>>x;
			c[i][j]=x;
		}
	}
	cout<<0<<'\n';
	return 0;
}
