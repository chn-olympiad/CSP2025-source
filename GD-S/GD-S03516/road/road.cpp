#include <bits/stdc++.h>
using namespace std;
const int N=1e6+20;
struct dr{
	int x;int y;int c;
};
dr d[N];//两城市+费用 
int c[11];
int a[N][N];//Ci到各城市的费用 
int l[N][N]; 
int f(int x,int y)
{
	
}
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>d[i].x>>d[i].y>>d[i].c;
		l[d[i].x][d[i].y]=d[i].c;
	}
	for(int i=1;i<=k;i++)
	{cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	} 

	return 0;
}
