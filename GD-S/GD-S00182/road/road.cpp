#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxk=15;
const int maxn=1e4+15;
const int maxm=1e6+5;
int fa[maxn],ct[maxk],c[maxk][maxn];
struct edge{
	int u,v,d;
	edge(){}
	edge(int uu,int vv,int dd){
		u=uu;
		v=vv;
		d=dd;
	}
	bool operator < (const edge &b) const {
		return d<b.d;
	}
}e[maxn],g[maxm];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	fa[y]=x;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		g[i]=edge(u,v,d);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&ct[i]);
		for(int j=1;j<=n;j++) scanf("%d",&c[i][j]);
	}
	
	sort(g+1,g+m+1);
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	int cnt=0;
	ll res=0;
	
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v,d=g[i].d;
		if(find(u)==find(v)) continue;
		res+=d;
		e[++cnt]=g[i];
		merge(u,v);
	}
	
	// printf("kk%lld\n",res);
	// fflush(stdout);
	
	for(int s=1;s<(1<<k);s++){
		ll ret=0;
		int tot=0,tt=0;
		for(int i=1;i<=k;i++){
			if(!((s>>(i-1))&1)) continue;
			tt++;
			ret+=ct[i];
			for(int j=1;j<=n;j++) g[++tot]=edge(n+tt,j,c[i][j]);
		}
		// printf("kk%d %lld\n",s,ret);
		// fflush(stdout);
		for(int i=1;i<=n+tt;i++) fa[i]=i;
		sort(g+1,g+tot+1);
		int now1=0,now2=0,now=0;
		while(now<n+tt-1){
			int u,v,d;
			if(now2>=tot||(now1<cnt&&e[now1+1].d<=g[now2+1].d)){
				now1++;
				u=e[now1].u;
				v=e[now1].v;
				d=e[now1].d;
			}else{
				now2++;
				u=g[now2].u;
				v=g[now2].v;
				d=g[now2].d;
			}
			if(find(u)==find(v)) continue;
			// printf("%d %d %d\n",u,v,d);
			now++;
			ret+=d;
			merge(u,v);
		}
		res=min(res,ret);
		// puts("ok");
		// fflush(stdout);
	}
	
	printf("%lld\n",res);
	
	return 0;
}