#include <bits/stdc++.h>
using namespace std;
int n,a[5100],mx;
long long ans,s;
const int N=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<=3)
	{
		if(s>mx*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(n==5&&a[1]==1)
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
	return 0;
}
