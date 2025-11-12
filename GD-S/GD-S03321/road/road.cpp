#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e4+7,M=2e6+7;
int n,m,k;ll ans;
struct line{
	int v;ll w;
};
struct line2{
	int u,v;ll w;
	bool operator<(const line2 &other) const{
		return w<other.w;
	}
};
int fa[N],siz[N];
line2 l[M];int cnt,tl;
void solve(){
	sort(l+1,l+cnt+1);
	for(int i=1;i<=cnt;i++){
		int u=l[i].u,v=l[i].v;ll w=l[i].w;
		while(u!=fa[u]) u=fa[u];
		while(v!=fa[v]) v=fa[v];
		if(u==v) continue; 
		if(siz[u]<siz[v]) swap(u,v);
		siz[u]+=siz[v];
		fa[v]=u;
		ans+=w;
		tl++;
		if(tl>=n+k-1) break;
	}
}
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		l[++cnt]=(line2){u,v,w};
	}
	for(int i=1;i<=k;i++){
		ll c; scanf("%d",&c);
		for(int j=1;j<=n;j++){
			ll w;
			scanf("%lld",&w);
			l[++cnt]=(line2){n+i,j,w};
		}
	}
	for(int u=1;u<=n+k;u++) fa[u]=u,siz[u]=1;
	solve();
	printf("%lld",ans);
	return 0; 
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
48pts 
*/
