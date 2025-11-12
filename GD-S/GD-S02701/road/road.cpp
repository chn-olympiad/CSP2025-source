#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+11,N=1e4+11;
int f[N],sum[N],c[21],f1[N];
int read()
{
	int k=0,l=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')l=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*l;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int find1(int x)
{
	if(f1[x]==x)return x;
	return f1[x]=find(f1[x]);
}
struct node
{
	int u,v,w,nw_num;
}road[M*21];
int nw[N][21];
bool pd[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
vector<int> p,onl,ls;
int n,m,k,ans=0;
void spe_A()
{
	ans=0;
	sort(road+1,road+1+m,cmp);
	int be=0,en=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(road[i].u),fy=find(road[i].v);
		if(fx!=fy)
		{
			ans+=road[i].w;
			p.push_back(i);
			if(p.size()==n-1)
				break;
			f[fx]=f[fy];
		}
	}
	printf("%lld",ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		road[i].u=read();
		road[i].v=read();
		road[i].w=read();
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	bool pd=1;
	int ans=0x3f3f3f3f;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i])
			pd=0;
		for(int j=1;j<=n;j++)
			nw[i][j]=read();
	}
	for(int l=1;l<=k;l++)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				road[++m].u=i;
				road[m].v=j;
				road[m].w=nw[l][i]+nw[l][j];
				road[m].nw_num=l;
			}
	}
	if(pd)
		spe_A();
	else
	{
		sort(road+1,road+1+m,cmp);
		for(int l=0;l<=(1<<k)-1;l++)
		{
			int lans=0;
			for(int i=1;i<=k;i++)
				if((1<<i-1)&l)
					lans+=c[i];
			int be=0,en=0,p1=0;
			for(int i=1;i<=n;i++)
				f1[i]=i;
			for(int i=1;i<=m;i++)
			{
				int fx=find1(road[i].u),fy=find1(road[i].v);
				if(road[i].nw_num&&((1<<road[i].nw_num-1)&l)==0)
					continue;
				if(fx!=fy)
				{
					f1[fx]=f1[fy];
					lans+=road[i].w;
					p1++;
					if(p1==n-1)
						break;
				}
			}
			if(p1==n-1)
				ans=min(ans,lans);
		}
		printf("%lld",ans);
	}
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
