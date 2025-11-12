#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 20005
#define M 2000005
#define lowbit(x) (x&-x)
ll LOG[N];
ll n,m,cnt,k;
struct edge{
	ll u,v,w;
};
edge g[M];
bool cmp(edge c1,edge c2){
	return c1.w<c2.w;
}
ll fa[N],c[15];
ll find(ll k){
	return fa[k]==k?k:fa[k]=find(fa[k]);
}
ll answer=2e18;
void work(){
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	ll newst=0;
	for(ll i=1;i<=cnt;i++){
		ll x=find(g[i].u),y=find(g[i].v);
		if(x!=y){
			fa[x]=y;
			g[++newst]=g[i];
		}
	}
	cnt=newst;
}
void kruskal(ll S,ll val){
	for(ll i=1;i<=n+k;i++){
		fa[i]=i;
	}
	ll tmp=0;
	for(ll i=1;i<=cnt;i++){
		if(g[i].u>n&&(S&(1ll<<g[i].u-n-1))==0){
			continue;
		}
		ll x=find(g[i].u),y=find(g[i].v);
		if(x!=y){
			fa[x]=y;
			tmp+=g[i].w;
		}
	}
	answer=min(answer,tmp+val);
}
ll sum[(1ll<<10)+5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	cnt=m;
	sort(g+1,g+1+cnt,cmp);
	work();
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			ll dat;
			cin>>dat;
			g[++cnt]=(edge){n+i,j,dat};
		}
	}
	sort(g+1,g+1+cnt,cmp);
	for(ll i=2;i<=(1ll<<k);i++){
		LOG[i]=LOG[i>>1]+1;
	}
	for(ll S=0;S<(1ll<<k);S++){
		if(S==0){
			kruskal(0,0);
			continue;
		}
		ll lower=LOG[lowbit(S)];
		sum[S]=sum[S-lowbit(S)]+c[lower+1];
		kruskal(S,sum[S]);
	}
	cout<<answer;
	return 0;
}
