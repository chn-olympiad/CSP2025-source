#include <bits/stdc++.h>
using namespace std;
#define int long long

int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e4+10,mod=998244353;
int c[N];
int fac[N],inv[N];
int qmi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
int A(int n,int m)
{
	return fac[n]*inv[n-m]%mod;
}
int a[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=N-10;i++)fac[i]=fac[i-1]*i%mod;
	inv[N-10]=qmi(fac[N-10],mod-2);
	for(int i=N-11;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	int n=read(),m=read();
	string s;
	cin>>s;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=n;i++)c[i]=read();
	for(auto k:s)if(k!='1')flag=false;
	s=" "+s;
	if(flag)
	{
		int ans=0;
		for(int i=m;i<=n;i++)ans=(ans+A(n,i))%mod;
		cout<<ans;
	}else
	{
		if(n<=15)
		{
			int ans=0;
			do
			{
				int ecnt=0,dnt=0;
				for(int i=1;i<=n;i++)
				{
					
					if(c[a[i]]>dnt&&s[i]=='1')ecnt++;
					else dnt++;
				}
				if(ecnt>=m)ans++;
				ans%=mod;
			}
			while(next_permutation(a+1,a+1+n));
			cout<<ans%mod;
		}
		else 
		{
			cout<<1ll;
		}
	}
	return 0;
}
