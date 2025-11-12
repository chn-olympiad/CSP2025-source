#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
const int N=1e6+1e4+5;
const int M=1e6+5;
struct node{
	int u,v,w;
}g[N],h[N];
int n,m,k;
int fa[M],val[11];
int f[11][M],a[11]={0};
int flag=0;
LL ans=1e18;
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	memcpy(g,h,sizeof(h));
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve(){
	init();
	int all=m,tol=n;
	LL cost=0;
	for(int i=1;i<=k;i++){
		if(a[i]==1){
			cost+=val[i];
			tol++;
			for(int j=1;j<=n;j++){
				all++;
				g[all].u=n+i;g[all].v=j;
				g[all].w=f[i][j];
			}
		}
	}
	sort(g+1,g+1+all,cmp);
	int now=0,i=0;
	while(now<tol-1){
		i++;
		int s=find(g[i].u),t=find(g[i].v);
		if(s!=t){
			fa[s]=t;
			cost+=(LL)g[i].w;
			now++;
		}
	}
	ans=min(ans,cost);
}
void dfs(int x){
	if(x==k){
		solve();return;
	}
	a[x+1]=1;dfs(x+1);
	a[x+1]=0;dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&h[i].u,&h[i].v,&h[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);
		if(val[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	if(flag==1){
		dfs(0);
		printf("%lld",ans);
	}
	else{
		init();
		int all=m,tol=n;
		LL cost=0;
		for(int i=1;i<=k;i++){
			tol++;
			for(int j=1;j<=n;j++){
				all++;
				h[all].u=n+i;h[all].v=j;
				h[all].w=f[i][j];
			}
		}
		sort(h+1,h+1+all,cmp);
		int now=0,i=0;
		while(now<tol-1){
			i++;
			int s=find(h[i].u),t=find(h[i].v);
			if(s!=t){
				fa[s]=t;
				cost+=(LL)h[i].w;
				now++;
			}
		}
		printf("%lld",cost);
	}
}
