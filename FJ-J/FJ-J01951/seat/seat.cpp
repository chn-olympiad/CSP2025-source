#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b,n,m,r,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	for(int i=1;i<=n*m;i++)
	{
		int flag=0;
		for(int j=1;j<=n*m-1;j++)
		{
			if(a[j]<=a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			b=i;
			break;
		}
	}
	r=((b-1)/n)+1;
	int d=r%2;
	if(b%n==0)
	{
		if(d==1)
		{
			c=n;
		}
		else
		{
			c=1;
		}
	}
	else
	{
		if(d==1)
		{
			c=b%n;
		}
		else
		{
			c=(n+1)-b%n;;
		}
	}
	cout<<r<<" "<<c;
	return 0;
} 
