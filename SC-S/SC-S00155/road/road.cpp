#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N=1e4+50;
ll n,m,k,dis[N],vis[N],c[15],ans;
struct jj{
	ll l,r;
};
vector<jj> s[N];
void adde(ll u,ll v,ll w){
	s[u].push_back({v,w});
}
struct node{
	ll dis,pos;
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
std::priority_queue<node> q;
void dijkstra(){
	q.push({0,1});
	dis[1]=0;
	while(q.size()!=0){
		ll x=q.top().pos;
		q.pop();
		if(vis[x]==1){
			continue;
		}
		vis[x]=1;
		for(ll i=0;i<s[x].size();i++){
			ll y=s[x][i].l;
			if(dis[y]>dis[x]+s[x][i].r){
				dis[y]=dis[x]+s[x][i].r;
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	while(m--){
		ll u,v,w;
		cin>>u>>v>>w;
		adde(u,v,w);
		adde(v,u,w);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			ll x;
			cin>>x;
			adde(n+i,j,x);
			adde(j,n+i,x);
		}
	}
	dijkstra();
	for(ll i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
	return 0;
}