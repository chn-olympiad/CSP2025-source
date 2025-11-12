#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=10015,M=1000005;
int n,m,k,tot; 
struct E{
	int u,v,w;
}e[M],e2[M];
int a[15][N],c[15];
ll ans=1e18,sum;
int cnt;
int fa[N];
int siz[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	sort(e+1,e+m+1,[&](E A,E B){
		return A.w<B.w;
	}); int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u); int v=find(e[i].v);
		if(u==v) continue;
		fa[u]=v; e[++cnt]={e[i].u,e[i].v,e[i].w};
	} m=cnt;
	for(int i=0;i<(1<<k);i++){
		sum=0; tot=0; cnt=0;
		for(int j=1;j<=k;j++) 
			if(i&(1<<j-1)) {
				sum+=c[j]; ++cnt;
				for(int w=1;w<=n;w++) e2[++tot]={n+j,w,a[j][w]};
			}
		sort(e2+1,e2+tot+1,[&](E A,E B){
			return A.w<B.w;
		});
		for(int i=1;i<=n+k;i++) 
			siz[i]=1,
			fa[i]=i;
		int p1=1; int p2=1; int nw=0;
		for(;nw<n+cnt-1&&sum<ans;){
			if(p2>tot||p1<=m&&e[p1].w<=e2[p2].w){
				u=find(e[p1].u); v=find(e[p1].v);
				if(u^v) {
					++nw,sum+=e[p1].w;
					if(siz[u]<siz[v]) 
						siz[v]++,
						fa[u]=v;
					else fa[v]=u,siz[u]++;
				} 
				++p1;
			} else {
				u=find(e2[p2].u); v=find(e2[p2].v);
				if(u^v) {
					++nw,sum+=e2[p2].w;
					if(siz[u]<siz[v]) 
						siz[v]++,
						fa[u]=v;
					else fa[v]=u,siz[u]++;
				}
				++p2;
			}
		}
		ans=min(ans,sum);
	} printf("%lld",ans);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
