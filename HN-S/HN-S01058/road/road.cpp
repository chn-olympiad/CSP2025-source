#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("road.in");
	ofstream fout("road.out");
	int n,m,k;
	fin>>n>>m>>k;
	int u[n],v[n],w[n];
	for(int i=1;i<=n;i++)
	{
		fin>>u[i]>>v[i]>>w[i];
	}
	int c[k],a[n][n];
	for(int i=1;i<=k;i++)
	{
		fin>>c[i];
		for(int j=1;j<=n;j++)
		{
			fin>>a[i][j];
		}
	}
	return 0;
}
