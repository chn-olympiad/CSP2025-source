#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[110],q = 1,a1,c,x,y;
	cin>>n>>m;
	for(int i =1;i<=n;i++)
	{
		for(int k = 1;k<=m;k++)
		{
			cin>>a[q];
			q++;
		}
	}
	a1 = a[1];
	sort(a+1,a+n*m+1);
	q = 1;
	for(int i =1;i<=n;i++)
	{
		for(int k = 1;k<=m;k++)
		{
			if(a[q] == a1)
			{
				c =n*m-q+1;
			}
			q++;
		}
	}
	if(c == 1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(c%n == 0)
	{
		x = c/n;
	}
	else
	{
		x = c/n+1;
	}
	if(x%2 == 1)
	{
		if(c%n == 0)
		{
			y = n;
		}
		else
		{
			y = c%n;
		}
	}
	else
	{
		if(c%n == 0)
		{
			y = 1;
		}
		else
		{
			y = n - c%n + 1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
