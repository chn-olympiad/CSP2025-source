#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=1e6+100,K=11;
const ll INF=1e18;
ll a[K][M],ans,c[K];
int fa[N],siz[N],n,m,k;
struct node{
	int u,v;
	ll w;
}e[M],g[N*K];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	if(siz[x]<siz[y])swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=1;
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&g[i].u,&g[i].v,&g[i].w);
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		} 
	} 
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(find(g[i].u)==find(g[i].v))continue;
		merge(g[i].u,g[i].v);
		e[++cnt]=g[i];
		if(cnt==(n-1)){
			break;
		}
	}
	m=cnt;
	ans=INF;
	for(int i=0;i<(1<<k);i++){
		init();
		ll sum=0,s=0;
		for(int j=1;j<=m;j++){
			g[j]=e[j];
		}
		cnt=m;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				s++;
				sum+=c[j];
				for(int q=1;q<=n;q++){
					g[++cnt]={j+n+1,q,a[j][q]}; 
				}
			}
		} 
		sort(g+1,g+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(find(g[i].u)==find(g[i].v))continue;
			merge(g[i].u,g[i].v);
			sum+=g[i].w;
		}
		if(siz[find(1)]==(n+s))ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
