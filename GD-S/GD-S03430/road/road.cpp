#include<queue>
#include<cstdio>
#include<algorithm>
const int N(10005);
using ll=long long;
using namespace::std;
struct edge
{
	int fr,to,val;
	bool operator<(const edge k)
	const{return val<k.val;}
}e[N*500];
int f[N];
int fnd(int k){return f[k]=f[k]==k?k:fnd(f[k]);}
int c[N],a[15][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,i,j;
	ll cnt(0),ans(0);
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=m;i++)
	  scanf("%d %d %d",&u,&v,&w),
	  e[i]=(edge){u,v,w};
	bool f1(true);
	int tot(m);
	for(i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		for(j=1;j<=n;j++)
		  scanf("%d",&a[i][j]);
		if(c[i])f1=false;
	}
	if(f1)
	{
		for(i=1;i<=k;i++)
		  for(j=1;j<=n;j++)
			e[++tot]=(edge){n+i,j,a[i][j]};
	}
	sort(e+1,e+tot+1);
	for(i=1;i<=n+k;i++)f[i]=i;
	for(i=1;i<=tot;i++)
	{
		u=fnd(e[i].fr),v=fnd(e[i].to);
		if(u==v)continue;
		f[u]=v,cnt++,ans+=e[i].val;
		if(cnt==n-1)break;
	}
	printf("%lld",ans);
	return ~~(0-0);
}
//Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£Àî¹ðÅ£ 
