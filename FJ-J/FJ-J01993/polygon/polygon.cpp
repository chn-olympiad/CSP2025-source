#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	const long long MOD=998244353;
	cin>>n;
	long long a[n],maxn=-1,sum=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n==3)
	{
		if(sum>2*maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=1;
	for(long long i=0;i<n;i++)
	{
		ans*=2;
		ans%=MOD;
	}
	ans-=1;
	ans-=n;
	ans-=(n*(n-1)/2);
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}
