#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define ll long long
using namespace std;
const int M=3e6+5;
struct str
{
	int x,y,z,id;
}a[M];
bool cmp(str fi,str se)
{
	return fi.z<se.z;
}
int n,m,k,x[M],y[M],z[M],len,b[15][M];
int cost[M],siz[M],fa[M],f[M],flag;
ll ans=1e18;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		a[++len]={x[i],y[i],z[i],0};
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&cost[i]);
		if(cost[i])flag=1;
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&b[i][j]);
			a[++len]={n+i,j,b[i][j],i};
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int tim=1;tim<=pow(2,k);++tim)
	{
		f[k]++;
		for(int i=k;i>=1;--i)
			if(f[i]==2)f[i]=0,f[i-1]++;
			else break;
		ll sum=0;
		for(int i=1;i<=n;++i)
			fa[i]=i,siz[i]=1;
		for(int i=1;i<=k;++i)
		{
			fa[i+n]=i+n;
			siz[i+n]=0;
			if(f[i])sum+=cost[i];
		}
		for(int i=1;i<=len;++i)
		{
			if(a[i].id&&!f[a[i].id])continue;
			int dx=find(a[i].x),dy=find(a[i].y);
			if(dx!=dy)
			{
				fa[dx]=dy;
				siz[dy]+=siz[dx];
				sum+=a[i].z;
			}
			if(siz[dy]==m)break;
		}
		ans=min(ans,sum);
	}
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
