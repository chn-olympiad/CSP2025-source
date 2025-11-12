#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,c,r;
bool cmp(int x,int y)
{
	if(x>=y)
		return true;
	else
		return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			y=i;
		}
	}
	if(y%n==0)
	{
		c=y/n;
		if((y/n)%2==0)
			r=1;
		else
			r=n;
		cout<<c<<" "<<r;
	}
	else if((y/n)%2==0)
	{
		c=y/n+1;
		if(y%n==0)
			r=n;
		else
			r=y%n;
		cout<<c<<" "<<r;
	}
	else
	{
		c=y/n+1;
		if(y%n==0)
			r=1;
		else
			r=(n+1)-(y%n);
		cout<<c<<" "<<r;
	}
	return 0;
}

