#include <bits/stdc++.h>

using namespace std;

const long long INF=LLONG_MAX-1;
const int N=1e4;

int n,m,k;
long long dis[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;	
		
	for(int i=0;i<n;i++)
		for(int k=0;k<n;k++)
			dis[i][k]=INF;
		
	int x,y,z;		
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		x--;y--;
		dis[x][y]=dis[y][x]=z;
	}
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					dis[j][i]=dis[i][j];
				}
	
	cin>>k;
	for(int i=0;i<m;i++)
		cin>>x;
	
	cout<<dis[0][n];
}
