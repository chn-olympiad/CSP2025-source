#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,w,k,c[12],a[1005][1005];
int dist[1005][1005];
int xiang[100005][1000005];
bool cityroad[10];
const int INF=0x3f3f3f3f;
int f[100005][3];
int mm[1000005];
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=a[i][j];
		}
	}
	//between city
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][l]+dist[l][j]<dist[i][j]);
				{
					dist[i][j]=dist[i][l]+dist[l][j];
					cityroad[l]=true;
				}
			}
		}
	}
	//city contect vellage
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=k;l++)
		{
			for(int j=1;j<=n;j++)
			{
				if(xiang[i][l]+xiang[l][j]<dist[i][j])
				{
					f[l][1]=f[l][1]+xiang[i][l]+xiang[l][j];
					f[l][2]+=dist[i][j];
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(f[i][1]+c[i]<f[i][2]) 
			mm[i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=k;l++)
		{
			if(mm[l])
			for(int j=1;j<=n;j++)
			{
				if(dist[i][j]>xiang[i][l]+xiang[l][j]);
				{
					dist[i][j]=xiang[i][l]+xiang[l][j];
				}
			}
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n/2;j++)
			if(dist[i][j]!=0&&dist[i][j]<INF) 
			{
				maxn=max(maxn,dist[i][j]);
			}
	}
	cout<<maxn;
	exit(0);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f3f3f3f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];//cityness feiyong
		for(int j=1;j<=n;j++)
		{
			int cost;
			cin>>cost;
			xiang[i][j]=xiang[j][i]=cost;
		}
	}
	floyd();
	return 0;
}