#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10005
#define M 1000005
#define inf 0x3f3f3f3f3f3f3f3f 
int n,m,k,ecnt,fa[N];
ll c[15],isv[15],minn=inf;
struct edg{ll u,v,w;}e[M],e1[M];
int fnd(int x){return (fa[x]==x?x:fa[x]=fnd(fa[x]));}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	stable_sort(e+1,e+m+1,[](const edg &a,const edg&b){return a.w<b.w;});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(fnd(u)==fnd(v)) continue;
		fa[fnd(u)]=fnd(v);
		e1[++ecnt]={u,v,w};
		if(ecnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			ll p;scanf("%lld",&p);
			e1[++ecnt]={j,n+i,p};
		}
	}
	stable_sort(e1+1,e1+ecnt+1,[](const edg &a,const edg&b){return a.w<b.w;});
	for(int i=0;i<(1<<k);i++){
		ll nd=n,ed=0,now=0;
		for(int j=0;j<k;j++){
			isv[j+1]=(i>>j&1);
			if(i>>j&1) nd++,now+=c[j+1];
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=ecnt;j++){
			ll u=e1[j].u,v=e1[j].v,w=e1[j].w;
			if(v>n&&!isv[v-n]) continue;
			if(fnd(u)==fnd(v)) continue;
			fa[fnd(u)]=fnd(v),ed++,now+=w;
			if(ed+1==nd) break;
		}
		minn=min(minn,now);
	}
	printf("%lld\n",minn);
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
