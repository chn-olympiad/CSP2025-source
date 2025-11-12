#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=1e4+15,M=2e6;
struct edge{
	ll v,w,nt;
}e[N];
ll h[N],ct,d[N],c[N],cct;
vector<pii>jl[N];
ll n,m,k;
ll ans=9999999999;
bool vis[N];
void add(ll x,ll y,ll z){
	e[++ct]={y,z,h[x]};
	h[x]=ct;
}
void dijkstra(ll s){
	for(ll i=1;i<=n+k;i++) d[i]=3e9;
	d[s]=0;
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,s});
	while(q.size()){
		pii t=q.top();q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=h[u];i;i=e[i].nt){
			int v=e[i].v;
			int w=e[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(u>n) jl[u].push_back({d[v],v});
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1,a;j<=n;j++){
			scanf("%lld",&a);
			add(j,i+n,a);
			add(i+n,j,a);
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		ll cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=d[j];
			//printf("%lld ",d[j]);
		}
		ans=min(cnt,ans);
		//printf("\n");
	}
	printf("%lld",ans);
	return 0;
}

