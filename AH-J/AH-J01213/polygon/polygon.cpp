#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],i,s[5005],ans=0,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[3]+a[1]>a[2])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
