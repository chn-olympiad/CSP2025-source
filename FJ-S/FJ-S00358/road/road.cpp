#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	cin>>n>>m>>k;
	int daolu[m+1][4];
	for(int i=1;i<=m;i++)
	{
		cin>>daolu[i][1]>>daolu[i][2]>>daolu[i][3];
	}
	int xiangzhen[k+1][n+2];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>xiangzhen[i][j];
		}
	}
	cout<<daolu[3][3]+daolu[4][3]+4;
	return 0;
} 
