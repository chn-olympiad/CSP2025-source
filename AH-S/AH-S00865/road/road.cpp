#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}a[1000005];
int n,m,k,fa[10005],flag[1005][1005],b[1005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void check()
{
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	int sum=0;
	for(int i=1;i<=m;i++)
		fa[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(fa[a[i].u]!=fa[a[i].v])
		{
			sum+=a[i].w;
			for(int j=1;j<=n;j++)
				if(j!=a[i].u&&fa[j]==fa[a[i].u]) fa[j]=fa[a[i].v];
			fa[a[i].u]=fa[a[i].v];
		}
	}
	cout<<sum<<endl;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0)
	{
		check();
		return 0;
	}
	memset(flag,127,sizeof(flag));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		flag[min(u,v)][max(u,v)]=w;
	}
	for(int i=1;i<=k;i++)
	{
		int d;
		cin>>d;
		for(int j=1;j<=n;j++) cin>>b[j];
		for(int j=1;j<=n;j++) 
			for(int k=j+1;k<=n;k++) 
				flag[j][k]=min(flag[j][k],b[j]+b[k]+d);
	}
	int idx=0;
	for(int j=1;j<=n;j++) 
		for(int k=j+1;k<=n;k++) 
			a[++idx]={j,k,flag[j][k]};
	n=idx;
	check();
	return 0;
}
