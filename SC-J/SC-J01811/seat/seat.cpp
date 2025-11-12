#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1;
int x;
int num=1;
int c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int people=n*m;
	cin>>a1;
	for(int i=2;i<=people;i++)
	{
		cin>>x;
		if(x>a1)
		{
			num++;
		 } 
	}
	if(num%n==0)
	{
		c=num/n;
	}
	else
	{
		c=num/n+1;
	}
	if(c%2==1)
	{
		r=num%n;
		if(r==0)
		{
			r=n;
		}
	}
	else
	{
		r=n-(num%n)+1;
		if(r==n+1)
		{
			r=1;
		}
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}