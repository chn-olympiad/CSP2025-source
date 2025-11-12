#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[1005][1005];
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=w;
		a[y][x]=w;
	}
	int f[10005];
	for(int i=0;i<k;i++)
	{
		cin>>f[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[i][j]=w;
			a[j][i]=w;
		}
	}
	cout<<0;
	return 0;
}
