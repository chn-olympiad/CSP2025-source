#include<bits/stdc++.h>
using namespace std;
int a[105],b,c,r,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
		{
			d=n*m+1-i;
			break;
		}
	}
	if(d<=n)
	{
		c=1;
		r=d;
	}
	else if(d/n%2==1)
	{
		if(d%n==0)
		{
			c=d/n;
			r=n;
		}
		else 
		{
			c=d/n+1;
			r=n+1-d%n;
		}
	}
	else if(d/n%2==0)
	{
		if(d%n==0)
		{
			c=d/n;
			if(c%2==0)
			{
				r=1;
			}
			else
			{
				r=n;
			}
		}
		else
		{
			c=d/n+1;
			if(c%2==1)
			{
				r=d%n;
			}
			else
			{
				r=n-d%n;
			}
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
