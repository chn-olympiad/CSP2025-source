#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,m_,mn,k,ans=1e18,fa[10011],c[11],d[11][10001];
struct edge
{
	int x,y,z;
	inline bool operator<(const edge a) const
	{
		return z<a.z;
	}
}a[1100001],b[1100001];
int getf(int x)
{
	if(x==fa[x])	return x;
	return fa[x]=getf(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>d[i][j];
	}
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1,j=0;i<=m&&j<n-1;i++)
	{
		int x=getf(a[i].x),y=getf(a[i].y);
		if(x==y)	continue;
		b[++m_]=a[i];
		fa[x]=y;
		j++;
	}
	for(int i=0;i<(1<<k);i++)
	{
		int p=0,C=0;
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1)))
			{
				p++;
				C+=c[j];
			}
		mn=m_;
		for(int j=1,x=1;j<=k;j++)
			if(i&(1<<(j-1)))
			{
				for(int k=1;k<=n;k++)	b[++mn]={n+x,k,d[j][k]};
				x++;
			}
		for(int i=1;i<=mn;i++)	a[i]=b[i];
		sort(a+1,a+mn+1);
		for(int i=1;i<=n+p;i++)	fa[i]=i;
		for(int i=1,j=0;i<=mn&&j<n+p-1;i++)
		{
			int x=getf(a[i].x),y=getf(a[i].y);
			if(x==y)	continue;
			C+=a[i].z;
			fa[x]=y;
			j++;
		}
		ans=min(ans,C);
	}
	cout<<ans;
	return 0;
}
