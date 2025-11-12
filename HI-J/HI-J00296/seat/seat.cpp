#include <bits/stdc++.h>;
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[1000],sum=0,b=0;
	cin >> n >> m;
	for (int i=0;i<m*n;i++)
	{
		cin >> a[i];
	}
	b=a[0];
	for (int i=0;i<m*n;i++)
	{
		if (a[i]>b)
		{
			sum++;
		}
	}
	if (sum%n==0)
	{
		c=sum/n+1;
		if (c%2==0)
		{
			r=n;
		}
		else
		{
			r=1;
		}
	}
	else
	{
		c=sum/n+1;
		if (c%2==0)
		{
			r=n-sum%n;
		}
		else
		{
			r=1+sum%n;
		}
	}
	cout << c  << " " << r;
	return 0;
}
