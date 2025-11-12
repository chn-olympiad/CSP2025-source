#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
    int a;
	a=n*m;
	int wh;
	cin>>wh;
	int wsy=1;
	for(int i=1;i<a;i++)
	{
		int ljh;
		cin>>ljh;
		if(ljh>wh)
		{
			wsy++;
		}
	}
	int c,d;
	if(wsy<n)
	{
		c=1;
	}
	else if(wsy%n==0)
	{
		c=wsy/n;
		
	}
	else
	{
		c=wsy/n+1;
	}
	if(c%2==1)
	{
		d=wsy%n;
	}
	else
	{
		d=n-wsy%n+1;
	}
	cout<<c<<" "<<d;
	return 0;
}
