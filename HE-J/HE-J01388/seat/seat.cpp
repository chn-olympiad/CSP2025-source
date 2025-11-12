#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int c,r;
int R;
int t;
int e;
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
		R=a[1];
		}else if(a[i]>a[i-1])
		{
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			e=i;
			break;
		}
	}
	if(e%n==0)
	{
		c=e/n;
		if(c%2==0)
		{
			r=1;
		}
		if(c%2==1)
		{
			r=n;
		}
	}else if(e%n==1)
	{
		c=(e/n)+1;
		int q=(e-1)/n;
		if(q%2==0)
		{
			r=1;
		}
		if(q%2==1)
		{
			r=n;
		}
	}else
	{
		c=e/n+1;
		if(c%2==1)
		{
			r=n-(e-n*(c-1))+1;
		}
		else
		{
			r=e-n*(c-1);
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
