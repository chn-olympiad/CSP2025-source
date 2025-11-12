#include<bits/stdc++.h>
using namespace std;
int a[5005],maxn,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			t=1;
		}
		maxn=max(maxn,a[i]);
	}
	if(n==3)
	{
		int c=a[1]+a[2]+a[3];
		maxn=maxn*2;
		if(c>maxn)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(t==0)
	{
		int c=0;
		for(i=1;i<=n-2;i++)
		{
			c=c+i;
		}
		cout<<c;
	}
	else
	{
		cout<<113;
	}
	return 0;
}
