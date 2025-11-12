#include<iostream>
using namespace std;
	int n,m,k;
	int u[100004][3]={0};
	int c[100004][1001]={0}
int bfs()
{
	
}
int main()
{
	freopen("road.in ","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i][0]>>u[i][1]>>u[i][2];
	}
		for(int i=0;i<k;i++)
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	bfs();
}
