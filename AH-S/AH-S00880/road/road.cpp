#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{int u,v,w;}f[2000100]={0};
int a[20]={0};
int b[10100];
int cmp(node i,node j)
{
	return i.w<j.w;
}
int find(int x)
{
	if(x==b[x])return x;
	else
	{
		b[x]=find(b[x]);
		return b[x];
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>f[i].u>>f[i].v>>f[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			f[m+i*n-n+j].u=n+i;
			f[m+i*n-n+j].v=j;
			cin>>f[m+i*n-n+j].w;
		}
	}
	sort(f+1,f+m+k*n+1,cmp);
	long long ans=0;
	for(int i=1;i<=m+k*n;i++)
	{
		int x=find(f[i].u),y=find(f[i].v);
		if(x!=y)
		{
			b[y]=x;
			ans+=f[i].w;
		}
	}
	cout<<ans;
	return 0;
}
