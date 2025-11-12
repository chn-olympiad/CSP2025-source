#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cost[n+k];
	int road[n+k][n+k];
	int ans=0;
	for(int i=0;i<n+k;i++)
	{
		for(int j=0;j<n+k;j++)
		{
			road[i][j]=-1; 
		}	
	}
	for(int i=0;i<m;i++)
	{
		cost[i]=0;
		int a,b,c;
		cin>>a>>b>>c;
		road[a-1][b-1]=c;
		road[b-1][a-1]=c;
	}
	for(int i=0;i<k;i++)
	{
		cin>>cost[i+n];
		for(int j=0;j<n;j++)
		{
			int co;
			cin>>co;
			road[i+n][j]=co;
			road[j][i+n]=co;
		}
	}
	int visit=1;
	int visited[n+k];
	int way[n+k];
	int len=0; 
	for(int i=0;i<n+k;i++)
	{
		visited[i]=0;
	}
	int start=0;
	while(visit!=n)
	{
		way[len]=start;
		visited[start]=1;
		int road_min=INT_MAX;
		int city=-1;
		for(int i=0;i<n+k;i++)
		{
			if(road[start][i]+cost[i]<road_min and visited[i]==0 and road[start][i]!=-1)
			{
				road_min=road[start][i]+cost[i];
				city=i;
			}
		}
		if(city!=-1)
		{
			ans=ans+road[start][city]+cost[city];
			start=city;
			len++;
			if(city<n)
			{
				visit++;
			}
		}
		else
		{
			len--;
			start=way[len];
		}
	}
	cout<<ans;
	return 0;
}
