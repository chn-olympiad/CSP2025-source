#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k,c[25],a[25][N],ans;
struct edge{
	ll v,w;
};
vector<edge> e[N];
bool beb[25];
bool vis[N];
ll dis[N];
struct node{
	ll u,dis;
	bool operator<(const node xx)const{
		return xx.dis<dis;
	}
};
priority_queue<node> pq;
ll getans(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.push({1,0});
	ll ans=0;
	while(!pq.empty()){
		ll u=pq.top().u;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		ans=ans+dis[u];
		for(auto i:e[u]){
			if(vis[i.v])continue;
			if(dis[i.v]>i.w){
				dis[i.v]=i.w;
				pq.push({i.v,dis[i.v]});
			}
		}
		for(int j=1;j<=k;j++){
			if(beb[j]){
				for(int k=1;k<=n;k++){
					if(vis[k])continue;
					if(dis[k]>a[j][k]+a[j][u]){
						dis[k]=a[j][k]+a[j][u];
						pq.push({k,dis[k]});
					}
				}
			}
		}
	}
	return ans;
}
void meij(ll x,ll z){
	if(x==k+1){
		ll sum=0;
		for(int i=1;i<=k;i++){
			if(z&1)beb[i]=1,sum+=c[i];
			z=z/2;
		}
		ans=min(ans,sum+getans());
		return ;
	}
	meij(x+1,z);
	meij(x+1,z+(1<<(x-1)));
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	ans=inf;
	meij(1,0);
	printf("%lld",ans);
	return 0;
} 
