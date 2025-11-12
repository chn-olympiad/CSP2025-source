#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e4+998,maxm=3e6+9;
ll n,m,k;
struct edge{
	ll u,v,w;
	bool operator<(const edge& other)const{
		return w<other.w;
	}
	
}e[maxm];
ll c[19];
ll cnt=0;
bool vis[19];
ll fa[maxn];
void init(){
	for(ll i=1;i<=n+k+1;++i)fa[i]=i;
}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	fa[y]=x;
}
bool issame(ll x,ll y){
	return find(x)==find(y);
}
ll kruskal(ll cntn){
	ll ans=0,cntm=0;
	for(ll i=1;i<=cnt;++i){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(!issame(u,v)){
			ans+=w;
			merge(u,v);
			++cntm;
			if(u>n){
				if(vis[u-n]){
					ans-=c[u-n];
				}else vis[u-n]=true;
			}
			if(cntm==cntn-1)return ans;
		}
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m>>k;
	init();
	for(ll i=1;i<=m;++i){
		ll u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	sort(e+1,e+cnt+1);
	ll ans=kruskal(n);
	for(ll i=1;i<=k;++i){
		cin>>c[i];
		for(ll j=1;j<=n;++j){
			ll w;
			cin>>w;
			e[++cnt]={n+i,j,w+c[i]};
		}
		init();
		memset(vis,0,sizeof(vis));
		sort(e+1,e+cnt+1);
		ans=min(ans,kruskal(n+i));
	}
	cout<<ans<<'\n';
	
	return 0;
}
