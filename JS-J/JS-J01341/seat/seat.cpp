#include<bits/stdc++.h>
using namespace std;
int m,n,a[10005],R,num,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==R)
		{
			num=m*n+1-i;
		}
	}	
	if(num%n==0)
	{
		c=num/n;
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
		c=num/n+1;
		if(c%2==0)
		{
			r=n-num%n+1;
		}
		else
		{
			r=num%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

