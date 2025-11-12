#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int>> grid(n+1,vector<int(n+i,10001))
	vector<int> mindist(n+1,1001);
	int m,n,k,v1,v2,val;
	int a[i];
	bool<int> visited(n+1,false);	
	cin>>m>>n>>k;
	int start=1;
	int end=m+1;	
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>val;
		grid[v1][v2]=val;
		grid[v2][v1]=val;
	}
	visited[start]=true;
	for(int i=m;i<k+m;i++)
	{
		cin>>a[1];
		for(int j=1;j<=m;j++)
		{
			cin>>val;
			grid[i][j]=val;
			grid[j][i]=val;
		}
	}
	for(int i=1;i<=m+1;i++)
	{
		int minval=INT_MAX;
		int cur=-1;
		for(int j=1;j<=m+1;j++)
		{
			if(!visited[j]&&mindist[j]<minval)
			{
				minval=mindiat[j];
				cur=j;
			}
		}
		visited[cur]=true;
		for(int j=1;j<m+1;j++)
		{
			if(!visited[j]&&grid[cur][j]+mindist[cur]<mindist[j])
			{
				mindist[j]=mindist[cur]+grid[cur][j];
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=m+1;i++)
	{
		cnt=cnt+mindist[i];
	}
	cout<<cnt+a[1];
	return 0;
}
