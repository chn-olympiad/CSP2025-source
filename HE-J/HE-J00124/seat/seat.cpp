#include<bits/stdc++.h>
using namespace std;
int a[105],a1,c,r;
int n,m,d;
bool tmp(int x,int y)
{
	return x>y;
}
int main()
{   
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		a1=a[1];
	}
	sort(a+1,a+1+n*m,tmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
		d=i;
	}
	if(d%n==0)
	{
		c=d/n;
		if(c%n%2!=0)
		{
			r=n;
		}else{
			r=1;
		}
	}
	else 
	{
		c=d/n+1;
		if(c%2!=0)
		{
			r=d%n;
		}
		else 
		r=n-d%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
	
}
