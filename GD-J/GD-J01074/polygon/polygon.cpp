#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

inline int read()
{
	int x=0,f=1;
	char ch=' ';
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void prt(ll x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) x=-x,putchar('-');
	int stac[20],top=0;
	while (x)
	{
		stac[++top]=x%10;
		x/=10;
	}
	while (top)
	{
		putchar(stac[top--]^48);
	}
	return;
}

const int maxn=5000+10,mod=998244353;

int n;
ll ans;
int a[maxn];

inline void BF()
{
	for (int i=0;i<n;i++)
	{
		a[i]=read();
	}
	for (int S=1;S<(1<<n);S++)
	{
		int maxa=0,suma=0,m=0;
		for (int i=0;i<n;i++)
		{
			if (S&(1<<i))
			{
				maxa=max(maxa,a[i]);
				suma+=a[i];
				m++;
			}
		}
		if (suma>maxa*2&&m>=3) ans++;
		if (ans>=mod) ans-=mod;
	}
	prt(ans);putchar('\n');	
}

ll jc[maxn],fjc[maxn],dp[maxn*maxn];

ll qpow(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1) ans=a*ans%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}

ll C(int x,int y)
{
	return jc[x]*fjc[y]*fjc[x-y]%mod;
}

inline void Try()
{
	jc[0]=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		jc[i]=jc[i-1]*i%mod;
		fjc[i]=qpow(jc[i],mod-2);
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++)
	{
		ll tmp1=0,tmp2=0;
		for (int j=1;j<=i-1;j++)
		{
			tmp1+=C(i-1,j);
		}
		for (int j=1;j<=n*n;j++)
		{
			dp[j]=0;
		}
		dp[0]=1;
		for (int j=1;j<=i-1;j++)
		{
			for (int k=a[i];k>=0;k--)
			{
				dp[k+a[j]]+=dp[k];
			}
		}
		for (int j=a[1]+a[2];j<=a[i];j++)
		{
			tmp2+=dp[j];
		}
		ans+=tmp1-tmp2;
		while (ans<0) ans+=mod;
		while (ans>=mod) ans-=mod;
	}
	prt(ans%mod);putchar('\n');
	
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	n=read();
	if (n<=20) BF();
	else Try();
	
	return 0;
}
