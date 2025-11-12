#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i==1)
		{
			r=b[i];
		}
	}
	int d=n*m;
	int t=0;
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n;i++)
	{
		t++;
		if(t%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=b[d];
				d--;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				a[i][j]=b[d];
				d--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}
