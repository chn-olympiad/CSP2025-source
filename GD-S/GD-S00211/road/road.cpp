#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+50;
const ll INF=1e16;
struct edge{int v,w;};
vector<edge> G[N];
struct nd{
	ll d,dis;
	bool operator < (const nd &x)const{return x.dis<dis;}
};
int n,m,k,a[12][N],c[N],vis[N];
ll dis[N],ans=INF;
ll prim(){
	ll sum=0;
	for(int i=1;i<=n+k;i++) dis[i]=INF,vis[i]=0;
	dis[1]=0;
	priority_queue<nd> q;
	q.push({1,0});
	while(!q.empty()){
		nd id=q.top();q.pop();
		if(vis[id.d]||id.dis!=dis[id.d]) continue;
		vis[id.d]=1,sum+=id.dis;
		for(auto v:G[id.d]){
			if(!vis[v.v]&&dis[v.v]>v.w){
				dis[v.v]=v.w;
				q.push({v.v,dis[v.v]});
			}
		}
	}return sum;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int f=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w}),G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) f=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) f=1;
		}
	}
	if(!f){
		cout<<0;
	}else{
		for(int i=0;i<(1<<k);i++){
			ll sum=0;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					for(int d=1;d<=n;d++) G[j+n].push_back({d,a[j][d]}),G[d].push_back({j+n,a[j][d]});
					sum+=c[j];
				}
			}
			sum+=prim();
			ans=min(ans,sum);
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					for(int d=1;d<=n;d++) G[j+n].pop_back(),G[d].pop_back();
				}
			}
		}cout<<ans;
	}
	return 0;
}
/*
1h
*/
