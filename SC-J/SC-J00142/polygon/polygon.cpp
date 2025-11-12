#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+15,mod=998244353;
ll f[N],a[N]; 
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) 
		{
			res=(res*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,k=0,mx=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		ll sum=0;
		for(ll j=mx;j>=1;j--)
		{
			if(j-a[i]>0)f[j]=(f[j]+f[j-a[i]])%mod;
			if(j==a[i]) f[j]+=1;
//			cout<<f[i][j]<<"\n";
		}
//		puts("\n\n")
		for(ll j=1;j<=a[i+1];j++)
		{
			sum=(sum+f[j])%mod;
		}
		if(i>=2&&i!=n)k=(k+sum)%mod;
	}
	ll ans=qmi(2,n);
	printf("%lld\n",(ans-(k+4+n-2)+mod)%mod);
	return 0;
} 
/*
5
2 2 3 8 10
浔阳江头夜送客，枫叶荻花秋瑟瑟。
主人下马客在船，举酒欲饮无管弦。
醉不成欢惨将别，别时茫茫江浸月。
忽闻水上琵琶声，主人忘归客不发。
循声暗问弹者谁，琵琶声停欲语迟。
移舟相近邀相见，添酒回灯重开宴。
..............................
同是天涯沦落人，相逢何必曾相识。
..............................
坐下泣闻谁最多，江州司马青衫湿！ 
%%%shiziyu111 tql%%%
%%%shiziyu tql%%%
*/