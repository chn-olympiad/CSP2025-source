#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
int g[N][N];
int a[N][100*N];
int c[N];
bool vis[N]={1,1};
unsigned long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,minnow=2e9;//c[105];
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=-1;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		//cout<<g[u][v]<<endl;//
		if(g[u][v]==-1&&g[v][u]==-1)
		{
			g[u][v]=g[v][u]=w;
		}
		else
		g[u][v]=g[v][u]=min(g[u][v],w);
		//cout<<g[u][v]<<endl;//
	}
	
	///
	/*
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		a[i][0]=c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int st=1;st<=n;st++)
		{
			for(int en=1;en<st;en++)
			{
				if(g[st][en]==-1&&g[en][st]==-1)
				{
					g[st][en]=g[en][st]=a[i][st]+c[i]+a[i][en];
				}
				g[st][en]=g[en][st]=min(g[st][en],a[i][st]+c[i]+a[i][en]);
			}
		}
	}
	//////
	/*
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	int now=1,nowp;
	for(int i=1;i<n;i++)
	{
		int minn=2e9;
		for(int j=1;j<=n;j++)
		{
			if(g[now][j]==-1)
			{
				continue;
			}
			if(i==j)
			{
				continue;
			}
			if(vis[j]==1)
			{
				continue;
			}
			if(g[now][j]<minn)
			{
				minn=g[now][j];
				nowp=j;
			}
			//minn=min(minn,g[now][j]);
		}
		ans+=minn;
		now=nowp;
		vis[now]=1;
		//cout<<"+"<<minn<<"("<<now<<endl;//
	}
	cout<<ans;
	
	return 0;
}
