#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10005],c[15][10005];
struct s{
	long long u,v,w;
}a[1000005];
bool cmp(s a,s b)
{
	return a.w<b.w;
}
int find(long long x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	bool g=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%lld",&c[i][j]);
			if(c[i][j]!=0)
			{
				g=0;
			}
		}
	}
	if(g==1&&k!=0)
	{
		printf("0");
		return 0;
	}
	if(k==0)
	{
		sort(a+1,a+1+n,cmp);
		long long h=0 ;
		for(int i=1;i<=m;i++)
		{
			long long u=a[i].u,v=a[i].v,w=a[i].w;
			long long uu=find(u),vv=find(v);
			if(uu!=vv)
			{
				fa[uu]=vv;
				h=h+w;
			}
		}
		printf("%lld",h);
		return 0;
	}
	
	return 0;
}
