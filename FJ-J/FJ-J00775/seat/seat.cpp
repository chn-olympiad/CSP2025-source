#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,x,y,z;
	cin>>n>>m;
	int a[n*m];
	for(int i = 0;i<n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	for(int i = 0;i<n*m;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				s=a[j];
				a[j]=a[i];
				a[i]=s;
			} 
		}
	}
	for(int i = 0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			x=i;
			break;
		}
	}
	if(x%n==0)
	{
		y=x/n;
	}
	else
	{
		y=x/n+1;
	}
	if(n%2==1)
	{
		if(x%n)
		{
			z=n;
		}
		else
		{
			z=x%n;
		}
	}
	else
	{
		z=n-x%n+1;
	}
	cout<<y<<" "<<z;
	return 0;
}
