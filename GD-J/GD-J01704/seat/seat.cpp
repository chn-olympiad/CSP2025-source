#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int d=n*m;
	int a[d+1];
	int ans[n+1][m+1];
	for(int i=1;i<=d;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+d);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans[i][j]=a[d];
			d--;
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==r)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==r)
			{
				cout<<i<<' '<<m-j+1;
				return 0;
			}
		}
	}
}
