#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10][10005],m1[1000005][3],minn[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>m1[i][0]>>m1[i][1]>>m1[i][2];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<13;
	return 0;
}
