#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c,d,e;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	b=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=i;j<n*m;j++)
		{
			if(c<a[j])
			{
				c=a[j];
				a[j]=a[i];
				a[i]=c;
			}
		}
		c=0;
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==b)
		{
			if((i+1)%n==0)
			{
				e=(i+1)/n;
			}
			else
			{
				e=(i+1)/n+1;
			}
			d=(i+1)%n;
			if(e%2==0)
			{
				if((i+1)%n!=n)
				{
					cout<<e<<" "<<d;
				}
				else
				{
					cout<<e<<" "<<n-d+1;
				}
			}
			else
			{
				cout<<e<<" "<<d;
			}
			return 0;
		}
	}
	return 0;
}
