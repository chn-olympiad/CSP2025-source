#include <bits/stdc++.h>
using namespace std;
int a[50005],n,maxa=-1,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=2;i<=n;i++)
	{
		maxa=max(a[i-1],a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for (int i=3;i<=n;i++)
	{
		if (sum>2*maxa)
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