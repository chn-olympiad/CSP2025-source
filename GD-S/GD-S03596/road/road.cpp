#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int l,r,w;
}a[1000005];
int n,m,k,c[15],b[15][100005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int fa[100005];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i; 
	sort(a+1,a+m+1,cmp);
	int l=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int xx=find(a[i].l),yy=find(a[i].r);
		if(xx!=yy)
		{
			fa[xx]=yy;
			ans+=a[i].w;
			l++;
			if(l==n-1) break;
		}
	}
	printf("%lld",ans);
	return 0;
}
