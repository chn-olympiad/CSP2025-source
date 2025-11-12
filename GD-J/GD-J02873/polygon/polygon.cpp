#include<bits/stdc++.h>
#define ll long long


using namespace std;

const ll N=5050,M=998244353;

ll mypow(ll a,ll b)
{
	ll sum=1;
	ll A=a;
	while(b)
	{
		if((b&1)==1)
		{
			sum*=A,sum%=M;
		}
		A*=A,A%=M;
		b>>=1;
	}
	return sum;
}

ll n;
ll a[N];
ll sum[N];

ll tp=0;

ll fac[N]={1};
ll inv[N]={1};

ll C(ll n,ll m)
{
	if(n<m||n==0||m==0) return 0;
	return fac[n]*inv[n-m]%M*inv[m]%M;
}

ll ss=0,lt=0;

ll ans=0;

void dfs(int x)
{
	if(x>n)
	{
		if(ss>lt)
		{
			++ans;
			if(ans>=M) ans-=M;
		}
		return;
	}
	
	ll t1=ss,t2=lt;
	
	ss+=lt;
	lt=a[x];
	dfs(x+1);
	ss=t1,lt=t2;
	dfs(x+1);
}

int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=mypow(fac[i],M-2);
	}
	
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) tp=1;
	}
	
	sort(a+1,a+n+1);
	
	if(tp==0)
	{
		for(ll i=n;i>=3;--i)
		{
			ans+=C(n,i);
			ans%=M;
		}
		printf("%lld",ans);
		return 0;
	}
	
	dfs(1);
	
	printf("%lld",ans);
	
	return 0;
}
