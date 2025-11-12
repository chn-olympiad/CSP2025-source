#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10015][10015],b[10050];
bool vis[10015][10015];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y>>a[x][y];
		a[y][x]=a[x][y];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[n+i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[n+i][j];
			a[j][n+i]=a[n+i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans+=a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}


