#include <iostream>
using namespace std;
int n,m,a[105],c,r,s,t;
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout"); 
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i]; 
	} 
	int x=a[1];
	for (int i=2;i<=n*m;i++)
	{
		if (a[i]>a[i-1])
		{
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
	}
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			s=i;
		}
	}
	for (int i=0;i<m;i++)
	{
		if (s/n==i)
		{
			if (s==n)
			{
				c=i;
				break;
			}
			else
			{
				c=i+1;
				break;
			}
		}
	}
	if (c%2==1)
	{
		if (s%n==0)
		{
			r=n;
		}
		else
		{
			r=s%n;
		}
	}
	else
	{
		r=n-s%n+1;
	}
	cout<<c<<" "<<r;
    return 0;
}
