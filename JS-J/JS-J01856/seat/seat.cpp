#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			x=i;
			break;
		}
	}
	x=n*m-x+1;
	if (x%n==0)
	{
		c=x/n;
		if (c%2==1)
			r=n;
		else
			r=1;
	}
	else
	{
		c=x/n+1;
		if (c%2==1)
			r=x%n;
		else
			r=n-x%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
