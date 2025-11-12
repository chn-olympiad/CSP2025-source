#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
const long long mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=n*(n-1)*(n-2)/6%mod;
	cout<<ans;
	return 0;
}
