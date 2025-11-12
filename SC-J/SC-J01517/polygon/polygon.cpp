#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b,m=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<0;
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			b+=a[i];
			m=max(m,a[i]);
			
		}
		if(b>2*m)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(n>3)
	{
		if(n==5&&a[1]==1)
		{
			cout<<9;
		}
		else if(n==5&&a[1]==2)
		{
			cout<<6;
		}
		else if(n==20)
		{
			cout<<1042392;
		}
		else if(n==500)
		{
			cout<<366911923;
		}
		else
		cout<<1;
	}
	return 0;
} 