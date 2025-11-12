#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

const int mod= 998244353,N=5010;

int n,a[N],f[N],ans;

int C(int x,int y)
{
	if(x==1) return y;
	if(x==y) return 1;
	return (f[y]/(f[x]*f[y-x]))%mod;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	f[1]=1;
	for(int i=2;i<=5000;i++)
		f[i]=f[i-1]*i%mod;
	for(int i=3;i<=n;i++)
	{
		ans+=C(i,n);
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}

inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

