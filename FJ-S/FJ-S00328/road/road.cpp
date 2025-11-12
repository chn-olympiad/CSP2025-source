#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+10,M=1.1e6+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
struct edge
{
	int a,b,c;
	bool operator<(const edge &b)const
	{
		return c<b.c;
	}
}e[M],tmp[M];
int n,m,k,p[N+15],c[15],news[15][N],nm;
int find(int x)
{
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		tmp[i]={a,b,c};
	}
	bool f=true;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i])f=false;
		for(int j=1;j<=n;j++)scanf("%d",&news[i][j]);
	}
	LL res=INF;
	if(!f)
	{
		for(int i=0;i<1<<k;i++)
		{
			nm=m;
			for(int j=1;j<=m;j++)e[j]=tmp[j];
			LL ans=0;
			int s=0;
			for(int j=0;j<k;j++)
				if(i>>j&1)
				{
					ans+=c[j+1];
					s++;
					for(int p=1;p<=n;p++)e[++nm]={n+j+1,p,news[j+1][p]};
				}
			sort(e+1,e+nm+1);
			for(int j=1;j<=n+s;j++)p[j]=j;
			for(int j=1;j<=nm;j++)
			{
				int pa=find(e[j].a),pb=find(e[j].b);
				if(pa!=pb)
				{
					p[pa]=pb;
					ans+=e[j].c;
				}
			}
			res=min(res,ans);
		}
	}
	else
	{
		for(int i=1;i<=m;i++)e[i]=tmp[i];
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)e[++m]={n+i,j,news[i][j]};
		sort(e+1,e+m+1);
		for(int i=1;i<=n+k;i++)p[i]=i;
		res=0;
		for(int i=1;i<=m;i++)
		{
			int pa=find(e[i].a),pb=find(e[i].b);
			if(pa!=pb)
			{
				p[pa]=pb;
				res+=e[i].c;
			}
		}
	}
	printf("%lld",res);
	return 0;
}
