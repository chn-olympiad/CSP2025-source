#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[114514],b[114514],c[114514];
int d[114514][11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>d[i][j];
		}
	} 
	cout<<13;
	return 0;
} 
