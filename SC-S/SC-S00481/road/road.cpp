#include <bits/stdc++.h>
using namespace std;
const int N=1e4+99,M=1e6+99
int dis[N][N];
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("rosd.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	for (int i=0,x,y,z;i<m;i++)
	{
		dis[i+1][i+1]=0;
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=dis[y][x]=z;
	}
	for (int k=i;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][f],dis[f][j]);
			}
		}
	}
}