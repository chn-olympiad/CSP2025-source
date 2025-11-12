#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m,k,u,v,w,p[20],c[1010],mi=1e8;
int a[1010][1010],b[20][10010];
void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=a[j][i]=min(a[i][k]+a[k][j],a[i][j]);
}
void dg(int now,int prize,int last)
{
	if(now>n)
	{
		mi=min(mi,prize);return;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			c[i]=1;
			dg(now+1,prize+a[last][i],i);
			c[i]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	for(int i=1;i<=m;i++) a[0][i]=0;
	for(int i=1;i<=k;i++)
	{
		cin>>p[i];
		for(int j=1;j<=n;j++)
		cin>>b[i][j];
	}
	floyd();
	dg(1,0,0);
	cout<<mi;
	return 0;
}

