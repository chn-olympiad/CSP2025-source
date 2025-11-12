#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
constexpr int K=11,N=1e4+55,M=1e6+55;
int n,m,k,ecnt;
struct node{
	int u,v;
	long long w;
}e[M<<1];
struct bcj{
	int f[N];
	inline int&operator[](int pos){return f[pos];}
	inline int find(int x){return (f[x]==x)?x:(f[x]=find(f[x]));}
	inline int merge(int x,int y){return f[find(x)]=find(y);}
}f[(1<<K)];
long long ne[K],ans[1<<K],ncnt;
inline bool cmp(node x,node y){return x.w<y.w;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);ecnt=m;
	for(int i=1;i<=ecnt;++i)scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=0;i<(1<<k);++i)for(int j=1;j<=n+k;++j)f[i][j]=j;
	for(int i=1;i<=k;++i){
		scanf("%lld",&ne[i]);
		for(int j=1;j<=n;++j)
		++ecnt,e[ecnt].u=n+i,e[ecnt].v=j,scanf("%lld",&e[ecnt].w);
	}
	sort(e+1,e+ecnt+1,cmp);
//	for(int i=1;i<=ecnt;++i)printf("(%d,%d):%lld\n",e[i].u,e[i].v,e[i].w);
	for(int i=0;i<(1<<k);++i)
	{
		for(int j=0;j<k;++j)if((i>>j)&1)ans[i]+=ne[j+1];
	}
	for(int i=1;i<=ecnt;++i){
		if(e[i].u<=n){
			if(f[0].find(e[i].u)==f[0].find(e[i].v))continue;
			f[0].merge(e[i].u,e[i].v),++ncnt,ans[0]+=e[i].w;
			for(int j=1;j<(1<<k);++j){
				if(f[j].find(e[i].u)!=f[j].find(e[i].v))
				ans[j]+=e[i].w,f[j].merge(e[i].u,e[i].v);
			}
		}else{
			int r=e[i].u-n-1;
			for(int j=1;j<(1<<k);++j){
				if(((j>>r)&1)&&(f[j].find(e[i].u)!=f[j].find(e[i].v)))
				ans[j]+=e[i].w,f[j].merge(e[i].u,e[i].v);
			}
		}
	}
	if(ncnt!=n-1)ans[0]=inf;
	for(int i=0;i<(1<<k);++i)ans[0]=min(ans[0],ans[i]);
	printf("%lld",ans[0]);
	return 0;
}
