#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
ll a[5005],T[5005][3];//0 1 2
ll ans;//>=3²»ºÏ·¨ 
ll fpow(ll x,ll y)
{
	ll ans=1,l=x;
	while(y)
	{
		if(y&1) ans=ans*l%mod;
		y>>=1;
		l=l*l%mod;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	T[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<=a[i];j++) ans=(ans+T[j][2])%mod;
		for(ll j=5000;j>=a[i];j--)
		{
			T[j][1]=(T[j][1]+T[j-a[i]][0])%mod;
			T[j][2]=(T[j][2]+T[j-a[i]][1])%mod;
			T[j][2]=(T[j][2]+T[j-a[i]][2])%mod;
		}
	}
	ans=(fpow(2,n)-ans+mod)%mod;
	ans--;//0
	ans-=n;//1 
	ans-=n*(n-1)/2;//2
	printf("%lld",(ans%mod+mod)%mod);
}
/*
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
stO YY0707 Orz stO Skyler_Yunxi Orz stO __yuanhaoran Orz stO less_than Orz stO 1vegetable Orz
*/ 
