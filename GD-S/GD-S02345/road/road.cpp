#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+7,M=1e6+7;
int n,m,k;
int u[M],v[M],fa[N];
int c[9],a[9][N],w[M];
ll ans;
struct node
{
	int u,v;
	int w;
}bian[10*M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void init()
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int getfa(int x)
{
	if(fa[x]!=x) return fa[x]=getfa(fa[x]);
	return x;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	init(); 
	for(int i=1;i<=m;i++)
	{
		cin>>bian[i].u>>bian[i].v>>bian[i].w;
	}
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		sort(bian+1,bian+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int fu=getfa(bian[i].u),fv=getfa(bian[i].v);
			if(fu==fv) continue;
			ans+=bian[i].w;
			fa[fv]=fu;
		}
		cout<<ans;
		return 0;
	}
	if(flag==0)
	{
		for(int K=1;K<=k;K++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j) continue;
					bian[++m].u=i;bian[m].v=j;bian[m].w=a[K][i]+a[K][j];
				}
			}
		}
		sort(bian+1,bian+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int fu=getfa(bian[i].u),fv=getfa(bian[i].v);
			if(fu==fv) continue;
			ans+=bian[i].w;
			fa[fv]=fu;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
