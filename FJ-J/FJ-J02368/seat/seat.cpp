#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b=1,c,r;
int main() 
{
	freopen("seat.in","w",stdin);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x = a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--)
	{
		if (a[i] == x)
		{
			break;
		}
		b++;
	}
	c = b/n;
	if (b%n != 0)
	{
		c++;
	}
	if (c%2 != 0)
	{
		r = b%n;
		if (r == 0)
		{
			r+=n;
		}
	}
	else
	{
		r = n-b%n-1;
		if (r == 0)
		{
			r+=n;
		}
	}
	for (int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<b<<endl;
	cout<<c<<" "<<r;
	freopen("seat.out","r",stdout);
	return 0;
}
