#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int u,v,w;
}b[100005];
int n,m,k,cnt;
int a[15][10005],f[10005];
bool vis[10005];
int find(int x)
{
	if(f[x]!=x)
	{
		f[x]=find(f[x]);
	}
	return f[x];
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		b[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	if(k==0)
	{
		int sum=0,tot=0;
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int a=find(b[i].u),c=find(b[i].v);
			if(a!=c)
			{
				f[a]=c;
				sum+=b[i].w;
				tot++;
			}
			if(tot==n-1)
			{
				break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
*/
