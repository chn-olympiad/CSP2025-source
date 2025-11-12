#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=3e6+10,N=2e4+10;
struct node
{
	int u,v,w;
}side[M];
int n,m,k,cnt,c[20],ci[20][N],fa[N],ans,nn;
int root(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=root(fa[x]);
		return fa[x];
	}
	return x;
}
void marge(int x,int y)
{
	int xx=root(x),yy=root(y);
	fa[xx]=yy;
}

bool cmp(node a,node b)
{
	return a.w<b.w;
}
void kru()
{
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(side+1,side+cnt+1,cmp);
	for (int i=1;i<=cnt&&nn<n-1;i++)
	{
		int u=side[i].u,v=side[i].v,w=side[i].w;
		fa[u]=root(fa[u]);
		fa[v]=root(fa[v]);
		if(fa[u]!=fa[v])
		{
			ans+=w;
			marge(u,v);
			nn++;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		side[++cnt].u=a;
		side[cnt].v=b;
		side[cnt].w=c;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			ci[i][j]=w;
		}
	}
	if(k>0)
	{
		for (int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for (int p=1;p<=k;p++)
			{
				side[++cnt].u=i;
				side[cnt].v=j;
				side[cnt].w=ci[p][i]+ci[p][j];
			}
		}
	}
	}
	
	kru();
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

