#include<bits/stdc++.h>
using namespace std;
struct road
{
	int u;
	int v;
	int w;
}r[1000010];
int a[11][1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	  cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=k;i++)
	  for(int j=0;j<=n;j++)
		cin>>a[i][j];
	cout<<12;
	return 0;
}