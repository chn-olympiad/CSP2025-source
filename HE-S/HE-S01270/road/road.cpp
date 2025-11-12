#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m-1][2];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>a[i][j];
		}
	}
	int z[k][n+1];
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>z[i][j];
		}
	}
	return 0;
}
