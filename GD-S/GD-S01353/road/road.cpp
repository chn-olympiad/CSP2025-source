#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
struct edge{
	int u,v; ll w;
}e[N],a[20];
int n,m,k,fa[N],flag;
ll ans=1e18,W,c[20],cnt,cntt;
bool vis[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy) fa[xx]=yy;
}
ll kluscal(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	ll res=0;
	for(int i=1;i<=m;i++){
		if(vis[e[i].u]|vis[e[i].v]) continue;
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			res+=e[i].w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int po=1<<k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]); cnt+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",&W);
			e[++m]={n+i,j,W};
		}
	}
	sort(e+1,e+m+1,cmp);
	if(cnt==0) ans=kluscal();
	else{
		for(int i=0,p,j;i<po;i++){
			p=i,j=1,cntt=cnt;
			while(p){
				if(p&1) vis[j+n]|=1,cntt-=c[j];
				j++,p>>=1;
			}
			ans=min(ans,kluscal()+cntt);
			for(int o=1;o<=k;o++) vis[n+o]&=0;
		}
	}
	printf("%lld",ans);
	return 0;
} 
