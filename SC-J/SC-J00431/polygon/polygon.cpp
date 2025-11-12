#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=22;
const int MOD=998244353;
long long n,a[N],sum[1<<N],maxx[1<<N],ans=0;
long long quick_pow(long long m,long long b)
{
	long long res=1,base=m;
	while(b)
	{
		if(b&1) res=res*base%MOD;
		base=base*base%MOD;
		b>>=1;
	}
	return res;
}
void solve1()
{
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long sta=0;sta<(1<<n);sta++)
		for(int i=1;i<=n;i++)
			if((sta>>(i-1))&1)
				sum[sta]+=a[i],maxx[sta]=max(maxx[sta],a[i]);
	for(long long sta=0;sta<(1<<n);sta++)
	{
		if(sum[sta]>2*maxx[sta])
		{
			ans++;
			if(ans>=MOD)
				ans-=MOD;
		}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	cout<<quick_pow(2,n)-1-n-n*(n-1)/2<<'\n';
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	IOS;
	cin>>n;
	if(n<=2)
	{
		cout<<0<<'\n';
		return 0;
	}
	if(n<=20)
		solve1();
	else
		solve2();
	return 0;
}