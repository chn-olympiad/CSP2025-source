#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m,d;
	cin>>n>>m;
	int a[110];
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1)
		{
			d=a[i];
		}
	}
	sort(a,a+n,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==d)
		{
			int h=(i+1)/m;
			cout<<h<<" ";
			if (h%2==1)
			{
				cout<<i-(h-1)*n+1;
			}
			else
			{
				cout<<m-(i-(h-1)*n)+1;
			}
		}
	}
	return 0;
}
