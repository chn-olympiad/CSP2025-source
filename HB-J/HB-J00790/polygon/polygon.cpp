#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m,sum=0,maxn=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>maxn)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
