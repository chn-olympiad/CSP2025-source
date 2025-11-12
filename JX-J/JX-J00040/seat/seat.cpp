#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[105],c;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[(i-1)*m+j];
		}
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[(i-1)*m+j]==c)
			{
				int k=(i-1)*m+j;
				if (((k-1)/n)%2==0)
				{
					cout <<(k-1)/n+1<<" "<<k%n+(k%n==0?n:0);
				}
				else
				{
					cout <<(k-1)/n+1<<" "<<n-(k%n+(k%n==0?n:0)-1);
				}
			}
		}
	}
	return 0;
				
}

