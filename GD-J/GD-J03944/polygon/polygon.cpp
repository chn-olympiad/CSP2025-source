#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=5e3;
const int mod=998244353;
ll n,sum=0,a[N],mmax=-0x3f3f3f3f3f3f3f3f,ans=0;
ll jc(ll x)
{
	ll cnt1=1;
	for(int i=2;i<=x;i++)
	{
		cnt1*=i%mod;
	}
	return cnt1;
}
ll C(ll n,ll x)
{
	ll cnt2=n;
	for(int i=1;i<x;i++)
	{
		cnt2*=(n-i)%mod;
	}
	return cnt2/jc(x)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
		mmax=max(mmax,a[i]);
	}
	if(n<3)
	{
		cout << 0 << endl;
		return 0;
	}
	else if(n==3)
	{
		if(sum > mmax*2) cout << 1 << endl;
		else cout << 0 << endl;	
	}
	else if(sum==n)
	{
		if(n%2==0){
			if(n==4)
			{
				cout << 5 << endl;
				return 0;
			}
			for(int i=3;i<n/2;i++)
			{
				ans+=C(n,i);
			}
			ans=ans*2+C(n,n-1)+C(n,n-2)+C(n,n/2)+1;
		}
		else{
			for(int i=3;i<=n/2;i++)
			{
				ans+=C(n,i);
			}
			ans=ans*2+C(n,n-1)+C(n,n-2)+1;
		}
		cout << ans << endl;
	}
	return 0;
}
