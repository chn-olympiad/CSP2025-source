#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],g[20][20],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[j][i]=a[j*n-n+i];
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		for(int j=2;j<=m;j+=2)
		{
			swap(g[j][i],g[j][n-i+1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==cnt)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

1 2


2 2
98 99 100 97

2 2
*/
