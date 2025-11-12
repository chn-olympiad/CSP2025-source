//最后一次了……要么1=，要么退役！ 
#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+1,M=1e4+1,K=11,INF=1000000000000000000;
long long fa[N],n,m,k,cnt;
struct edge{
	long long u,v,w;
}a[N],b[N],g[N];
bool flag=true;
long long p[M][M],ans=INF,jj[K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long Find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void he(long long x,long long y){
	fa[Find(x)]=Find(y);
}
void dfs(long long step,long long tut){
	if(step==k+1){
		cnt=0;
		for(long long i=1;i<=n+k;++i)fa[i]=i;
		for(long long i=1;i<n;++i){
			g[++cnt].u=b[i].u;
			g[cnt].v=b[i].v;
			g[cnt].w=b[i].w;
		}
		for(long long i=1;i<=k;++i){
			if(jj[i]==1){
				for(long long j=1;j<=n;++j){
					g[++cnt].u=n+i;
					g[cnt].v=j;
					g[cnt].w=p[i][j];
				}
			}
		}
		long long tmp=0,jb=0;
		sort(g+1,g+1+cnt,cmp);
		for(long long i=1;i<=cnt;++i){
			if(Find(g[i].u)==Find(g[i].v)){
				continue;
			}
			he(g[i].u,g[i].v);
			tmp+=g[i].w;
		}
		ans=min(ans,tmp+tut);
		return;
	}
	if(!flag)dfs(step+1,tut);
	jj[step]=1;
	dfs(step+1,tut+p[step][0]);
	jj[step]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;++i)fa[i]=i;
	for(long long i=1;i<=m;++i){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(long long i=1;i<=k;++i){
		for(long long j=0;j<=n;++j){
			scanf("%lld",&p[i][j]);
		}
		if(p[i][0]!=0)flag=false;
	}
	sort(a+1,a+1+m,cmp);
	for(long long i=1;i<=m;++i){
		if(cnt==n-1)break;
		if(Find(a[i].u)==Find(a[i].v)){
			continue;
		}
		he(a[i].u,a[i].v);
		b[++cnt].u=a[i].u;
		b[cnt].v=a[i].v;
		b[cnt].w=a[i].w;
	}
	dfs(1,0);
	printf("%lld",ans);
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
