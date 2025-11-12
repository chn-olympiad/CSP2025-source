#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","R",stdin);
	freopen("seat.out","W",stdout);
	int n,m,a[105],x,c=0,r,temp,pos;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			x=a[i];
		}
		temp=i;
		while(a[temp]>a[temp-1])
		{
			swap(a[temp],a[temp-1]);
			temp--;
		}
		
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==x)
		{
			pos=i+1;
			break;
		}
	}
	if(pos/n==0)
	{
		c=pos/n;
	}
	else
	{
		c+=pos/n+1;
	}
	if(c%2==1)
	{
		r=pos%n;
	}
	else
	{
		r=n-pos%n;
	}
	if(r==0)
	{
		r++;
	}
	if(pos%n==0)
	{
		c=pos/n;
	}
	else
	{
		c+=pos/n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
