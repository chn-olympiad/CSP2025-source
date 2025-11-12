#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10000] = {};
	long long ans,mod = 998244353;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n == 3)
	{
		if(a[3] + a[2] + a[1] > a[3]*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}

	}
	
	for(int len = 3;len<=n;len++)
	{
		for(int i = n;i>=len;i--)
		{
			int cnt = a[i]*2;
			cnt = cnt-a[i];
			ans++;
		}
	}
	cout<<ans%mod;
	return 0;
}