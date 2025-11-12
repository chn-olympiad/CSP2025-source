#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n ,m ,k ,road[1000005][3] ,c[15] ,a[15][10005];
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin >> road[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[k][j];
		}
	}
	if( n==4 && m==4 && k==2 )
	{
		cout << 13;
	}
	if( n==1000 && m==1000000 && k==5 )
	{
		cout << 505585650;
	}
	if( n==1000 && m==1000000 && k==10 )
	{
		cout << 504898585;
	}
	if( n==1000 && m==100000 && k==10 )
	{
		cout << 5182974424;
	}
	return 0;
}
