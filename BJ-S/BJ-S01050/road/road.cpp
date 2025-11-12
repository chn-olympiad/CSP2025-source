#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int fa[N],size[N],head[N];
int n,m,k;
ll ans;
ll cou[12][N],bcon[12];

struct res{
	int p;ll w;
};
struct newedge{
	int v=0,nex=0;
	ll w;
}ne[N];
struct edge{
	int u,v;ll w;
}e[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		size[i]=1;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void sunion(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(size[x]<size[y]) swap(x,y);
	fa[y]=x;
	size[x]+=size[y];
}
void mst(){
	int p=0;
	init();
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		sunion(e[i].u,e[i].v);
		ans+=e[i].w;
		ne[++p].v=e[i].v,ne[p].nex=head[e[i].u],ne[p].w=e[i].w,head[e[i].u]=p;
		ne[++p].v=e[i].u,ne[p].nex=head[e[i].v],ne[p].w=e[i].w,head[e[i].v]=p;
	}
}
ll dfs(int x,int fa,int numc,queue<res>& qe){
	ll js=0;
	for(int i=head[x];i;i=ne[i].nex){
		if(ne[i].v==fa) continue;
		if(cou[numc][ne[i].v]<=ne[i].w){
			js+=ne[i].w-cou[numc][ne[i].v];
			js+=dfs(ne[i].v,x,numc,qe);
			if(ne[i+1].v==x){
				qe.push({i,ne[i].w});
				ne[i].w=ne[i+1].w=cou[numc][ne[i].v];
			}else{
				qe.push({i-1,ne[i].w});
				ne[i].w=ne[i-1].w=cou[numc][ne[i].v];
			}
		}
	}
	return js;
}
void dg(int numc,ll cost){
	ll ncost =cost;
	ncost+=bcon[numc];
	ncost+=cou[numc][cou[numc][0]];
	queue<res> qe;
	ncost-=dfs(cou[numc][0],0,numc,qe);
	if(ncost<=ans){
		ans=ncost;
		dg(numc+1,ncost);
	}
	while(qe.size()){
		res t=qe.front();qe.pop();
		ne[t.p].w=ne[t.p+1].w=t.w;
	}
	if(numc<k) dg(numc+1,cost);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&bcon[i]);
		cou[i][0]=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&cou[i][j]);
			if(cou[i][j]<cou[i][cou[i][0]]) cou[i][0]=j;
		}
	}
	mst();
	dg(1,ans);
	printf("%lld",ans);
	return 0;
}
