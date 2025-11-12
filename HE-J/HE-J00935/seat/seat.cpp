#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[12][12],b[200];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int bb=b[1],mm=n*m;
	sort(b+1,b+n*m+1);
	for (int i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if (b[mm]==bb)
				{
				    cout<<i<<" "<<j;
				    return 0;
				}
				a[i][j]=b[mm];
				mm--;
			}
		}
		if (i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if (b[mm]==bb)
				{
				    cout<<i<<" "<<j;
				    return 0;
				}
				a[i][j]=b[mm];
				mm--;
			}
		}
	}
	return 0;
}
