#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > adj[10050],na[10050];
ll n,m,k,c[15],perm=0;
ll ans=0x3f3f3f3f3f3fffff;
struct node{
	ll i;
	ll dis;
	bool operator <(const node& comp) const{
		return dis>comp.dis;
	}
};
void run(){
	ll sum=0;
	ll i=1;
	bool act[10050];
	memset(act,0,sizeof(act));
	ll tperm=perm;
	while(tperm){
		if(tperm&1){
			sum+=c[i];
			act[i+n]=true;
		}
		tperm>>=1;
		i++;
	}
	ll dis[10050];
	bool vis[10050];
	priority_queue<node> pq;
	pq.push({1,0});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	while(pq.size()){
		ll u=pq.top().i;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		sum+=dis[u];
		dis[u]=0;
		for(auto v:adj[u]){
			ll ii=v.first;
			ll w=v.second;
			if(dis[ii]>dis[u]+w){
				dis[ii]=dis[u]+w;
				pq.push({ii,dis[ii]});
			}
		}
		for(auto v:na[u]){
			ll ii=v.first;
			ll w=v.second;
			if(ii<=n||act[ii]){
				if(dis[ii]>dis[u]+w){
					dis[ii]=dis[u]+w;
					pq.push({ii,dis[ii]});
				}
			}
		}
	}
	ans=min(ans,sum);
	return;
}
void getper(){
	while(perm<(1<<k)){
		run();
		perm++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll u,v;
		ll w;
		scanf("%lld %lld %lld",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++){
			ll w;
			scanf("%lld",&w);
			na[i+n].push_back(make_pair(j,w));
			na[j].push_back(make_pair(i+n,w));
		}
	}
	getper();
	cout<<ans<<endl;
	return 0;
}
