#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m,b[105],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+n+1);
	int x=1;
	for (int i=1;i<=m;i++)
	{
		if (m%2==1)
		{
			for (int j=1;j<=n;j++)
			{
				a[j][i]=b[x];
				x++;
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				a[j][i]=b[x];
				x++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==r)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
}

