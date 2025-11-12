#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int m,n,a[50000],b,c;
	cin>>n>>m;//hang lie
	for(int i=1;i<=(n*m);i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=(n*m);i++)
	{
		if(a[i]==b)
		{
			c=i;
			break;
		}
	}
	c=m*n-c+1;
	int d=c;
	if(c%n==0)
	{
		c=c/n;
		cout<<c<<" ";
		if(c%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		c=c/n+1;
		cout<<c<<" ";
		if(c%2==1)
		{
			cout<<d-(c*n)+1;
		}
		else
		{
			cout<<n-(d-(c*n)+1);
		}
	}
	
	return 0;
}
