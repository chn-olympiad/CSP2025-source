#include<bits/stdc++.h>
using namespace std;
int n,m,k,p[20005],d[256],e[13][20005],nn,mm;
long long ans=0x7fffffffffffffff;
bool f[13];
struct node
{
	int x,y,d;
} a[2000005],b[2000005],c[2000005];
int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void jspx()
{
	for (int k=0;k<31;k+=8)
	{
		for (int i=1;i<=mm;++i)
		++d[b[i].d>>k&255];
		for (int i=1;i<256;++i)
		d[i]+=d[i-1];
		for (int i=mm;i>0;--i)
		c[d[b[i].d>>k&255]--]=b[i];
		for (int i=1;i<=mm;++i)
		b[i]=c[i];
		for (int i=0;i<256;++i)
		d[i]=0;
	}
}
void dfs(int x)
{
	if (x<=k)
	{
		if (e[x][0])
		{
			f[x]=0;
			dfs(x+1);
		}
		f[x]=1;
		dfs(x+1);
	}
	else
	{
		int x,y;
		long long res=0;
		nn=n;
		mm=m;
		for (int i=1;i<=mm;++i)
		b[i]=a[i];
		for (int i=1;i<=k;++i)
		if (f[i])
		{
			res+=e[i][0];
			++nn;
			for (int j=1;j<=n;++j)
			b[++mm]=(node){j,nn,e[i][j]};
		}
		for (int i=1;i<=nn;++i)
		p[i]=i;
		jspx();
		for (int i=1;i<=mm;++i)
		{
			x=find(b[i].x);
			y=find(b[i].y);
			if (x!=y)
			{
				p[x]=y;
				res+=b[i].d;
			}
		}
		ans=min(ans,res);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].d);
	for (int i=1;i<=k;++i)
	for (int j=0;j<=n;++j)
	scanf("%d",&e[i][j]);
	dfs(1);
	cout<<ans;
	return 0;
}
