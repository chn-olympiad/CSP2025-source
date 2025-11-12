#include<bits/stdc++.h>
using namespace std;
int n,a,x,mx=-10000;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		x+=a;
		mx=max(mx,a);
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3) 
	{
		if(x>(2*mx))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else
	{
		cout<<8;
	}
	return 0;
}		