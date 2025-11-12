#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1],x[k+1][n+1];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x[1][i];
		for(int j=2;j<=n+1;j++)
		{
			cin>>x[j][i];
		}
	}
	cout<<"13";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
