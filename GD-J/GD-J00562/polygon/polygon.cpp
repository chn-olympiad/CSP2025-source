#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000000];
long long ans[1000000];


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long num=0;
	long long maxn=-9999999;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
		num+=a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		if(num>2*maxn)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	
	
	return 0;
}
