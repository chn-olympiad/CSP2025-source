#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int u[10005],v[10005],w[10005],country[11][10005];

bool mean(int o, int p, int q;)
{
	if(o+p<=p+q)
	{
		return 0;
	}
	else{
		return 1;}
	                          

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		cin>>country[j][1];
		for(int i=2;i<=n+1;i++)
		{
			cin>>country[j][i];
		}
	}
	cout<<country[1][2]*n;
	return 0;
}
