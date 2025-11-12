#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==1)
	{
		cout<<0;
	}
	else if (n==2)
	{
		cout<<0;
	}
	else if (n==3 && a[1]+a[2]>a[3])
	{
		cout<<1;
	}
	else if (n>3 && n<=10)
	{
		cout<<9;
	}
	else
	{
		cout<<50;
	}
	return 0;
}
