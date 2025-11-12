#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
int n,m,k,ans,p;
int a[10005][15],c[15];
bool v1[10005][15],v2[15];
struct E{
	int u,v,w,j;
	bool f;
}e[N];
inline void adde(int u,int v,int w,int j,bool f){
	e[++p]={u,v,w,j,f};
}
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kruscal(){
	int cnt=0;
	for(int i=1;i<=p;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y;
		if(e[i].f)v1[u][e[i].j]=v1[v][e[i].j]=v2[e[i].j]=1;
		else ans+=w;
		if(++cnt==n-1)break;
	}
}
bool cmp(E a,E b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1,u,v,w;i<=m;++i)
	scanf("%lld%lld%lld",&u,&v,&w),
	adde(u,v,w,0,0);
	for(int j=1;j<=k;++j){
		scanf("%lld",c+j);
		for(int i=1;i<=n;++i)
		scanf("%lld",&a[i][j]);
	}
	for(int x=1;x<=n;++x)
	for(int y=x+1;y<=n;++y)
	for(int j=1;j<=k;++j)
	adde(x,y,a[x][j]+a[y][j]+c[j],j,1);
	sort(e+1,e+p+1,cmp);
	kruscal();
	for(int i=1;i<=n;++i)
	for(int j=1;j<=k;++j)
	ans+=v1[i][j]?a[i][j]:0;
	for(int j=1;j<=k;++j)
	ans+=v2[j]?c[j]:0;
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0; 
} 
