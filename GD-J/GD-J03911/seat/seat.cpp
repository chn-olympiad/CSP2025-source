#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001],x,o;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin >>a[(i-1)*m+j];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			o=(i-1)*n+j;
			if (a[o]==x)
			{
				cout <<o/n+(o%n!=0)<<" ";
				if ((o/n+(o%n!=0))%2==0)
				{
					if (o%n==0)
						cout <<1;
					else
						cout <<n-o%n+1;
				}
				else
				{
					if (o%n==0)
						cout <<n;
					else
						cout <<o%n;
				}
				break;
			}
		}
	}
	return 0;
}
