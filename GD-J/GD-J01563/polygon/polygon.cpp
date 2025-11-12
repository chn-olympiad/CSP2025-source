#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=5005,mod=998244353,ny_2=499122177;
ll n,a[M],ans;
bool flag=1;
ll Pow(ll x,ll y)
{
	ll op=1;
	while(y)
	{
		if(y&1) op=op*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return op;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=0;
		}
	}
	if(flag)
	{
		cout<<((Pow(2,n)+mod-1-n)%mod+mod-n*(n-1)%mod*ny_2%mod)%mod;
		return 0;
	}
	for(int i=7;i<(1<<n);i++)
	{
		ll sum=0,Max=0,cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((i>>(j-1))&1)
			{
				sum+=a[j];
				Max=max(Max,a[j]);
				cnt++;
			}
		}
		if(sum>Max*2&&cnt>=3)
		{
			ans=(ans+1)%mod;
		}
	}
	cout<<ans;
	return 0;
}


