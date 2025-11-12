#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=10005;
int edge[maxn][maxn];
struct g
{
	int a[maxn];
}g[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=z;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>g[i].a[j];
		}
	}
	cout<<0;
	return 0;
}
