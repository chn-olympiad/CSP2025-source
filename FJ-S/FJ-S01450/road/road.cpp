#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
struct node{
	ll v,w;
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
ll n,m,k,dis[200005];vec<node> G[200005];bool vis[200005];
void add(ll u,ll v,ll w){
	G[u].pb((node){v,w});
	G[v].pb((node){u,w});
}
void dij(ll s){
	priority_queue<node> q;q.push({s,0});
	for(ll i=1;i<=n+k;i++) dis[i]=inf; 
	dis[s]=0;
	while(!q.empty()){
		node u=q.top();q.pop();
		vis[u.v]=1;
		for(auto v:G[u.v]){
			if(vis[v.v]) continue;
			if(dis[v.v]>dis[u.v]+v.w){
				dis[v.v]=dis[u.v]+v.w;
				q.push({v.v,dis[v.v]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;add(u,v,w);
	}
	if(k==0){
		dij(1);
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=dis[i];
		cout<<ans<<endl; 
	}else{
		for(ll i=1;i<=k;i++){
			ll x;cin>>x;
			for(ll j=1;j<=n;j++){
				ll w;cin>>w;
				add(n+i,j,w);
			} 
		}
		dij(1);
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=dis[i];
		cout<<ans<<endl;
	} 
	return 0;
}
/*
4 5 0
1 2 3
1 3 5
2 3 1
3 4 5
3 5 2
*/

