#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			s=a[i];
		}
	}
	for(int i=0;i<n*m;i++)
	{
		for(int j=i+1;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			c=i;
		}
	}
	if(c%n==0)
	{
		int q=c/n;
		if(q%2==0)
		{
			cout<<q<<" "<<'1';
		}
		else
		{
			cout<<q<<" "<<n;
		}
	}
	else
	{
		int q=c/n+1;
		if(q%2==0)
		{
			cout<<q<<" "<<n-(c%n)+1;
		}
		else
		{
			cout<<q<<" "<<c%n;
		}
	}
	return 0;	
} 
