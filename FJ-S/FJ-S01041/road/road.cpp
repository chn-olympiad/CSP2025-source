#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	ll u,v,w;
}G[1200005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll n,m,k,fa[10025],ans,cnt,cnt2,c[15][10005];
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool flag=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&G[i].u,&G[i].v,&G[i].w);
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		if(c[i][0]!=0) flag=0;
		for(ll j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		} 
	}
	if(!k){
		sort(G+1,G+m+1,cmp);
		for(ll i=1;i<=m;i++){
			ll u=find(G[i].u),v=find(G[i].v),w=G[i].w;
			if(u!=v){
				fa[u]=v;
				ans+=w;
				++cnt2;
				if(cnt2==n-1) break;
			}
		}
		printf("%lld",ans);
	}
	else if(flag){
		cnt=m;
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				G[++cnt].u=n+i;
				G[cnt].v=j;
				G[cnt].w=c[i][j];
			}
		}
		sort(G+1,G+cnt+1,cmp);
		for(ll i=1;i<=cnt;i++){
			ll u=find(G[i].u),v=find(G[i].v),w=G[i].w;
			if(u!=v){
				fa[u]=v;
				ans+=w;
				++cnt2;
				if(cnt2==n+k-1) break;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
