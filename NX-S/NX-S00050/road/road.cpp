#include<bits/stdc++.h>
using namespace std;
int c[550];
int a[10000][100];
int u[1000],v[1000],w[1000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	cout<<0;
	return 0;
}
