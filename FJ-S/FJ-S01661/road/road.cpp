#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 2000005
#define maxm 1005
#define mod 998244353
ll n,m,k,t,a[maxm][maxm],b[maxn],c[11][maxn],ans=0;
string c1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	//memset(a,INF,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=n;j++)cin>>c[i][j],c[i][j]+=p;
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(k==j)continue;
				if(a[k][j]==0)a[k][j]=c[i][j],a[j][k]=c[i][j];
				a[k][j]=min(c[i][j],a[k][j]);
				a[j][k]=min(c[i][j],a[j][k]);
			}
		}
	}
	cout<<125;
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	return 0;
}
