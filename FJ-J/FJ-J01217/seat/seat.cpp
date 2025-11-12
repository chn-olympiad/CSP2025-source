#include <bits/stdc++.h>
using namespace std;
int n,x,m,c,r,o[101][101],s[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++)
	{
		cin>>s[i];
	}
	x=s[0];
	sort(s+1,s+n*m+1);
	for (int j=1;j<=m;j++)
	{
		if (j%2==1)
		{
			for (int i=1;i<=n;i++)
			{
				s[i]==o[n][m];
			}
		}
		else
		{
			for (int i=n;i>=1;i++)
			{
				s[i]==o[n][m];
			}
		}
	}
	for (int j=1;j<=n;j++)
	{
		for (int i=1;i<=m;i++)
		{
			if (o[i][j]==x)
			{
				c=i;
				r=j;
				break;
			}
		}
	}
	cout<<c<<r;
	return 0;
}
