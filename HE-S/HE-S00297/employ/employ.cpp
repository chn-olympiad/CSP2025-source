#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();
const int N = 555,mod=998244353;

int f[N],ans;

int A(int x,int y)
{
	return (f[y]/f[x-1])%mod;
}

int C(int x,int y)
{
	if(x==y) return 1ll;
	if(x==1) return y;
	return (f[y]/(f[x]*f[y-x]))%mod;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read(),c[N]={},cc=0;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		if(c[i]==0) cc++;
	}
	if(n-cc<m) 
	{
		printf("0");
		return 0;
	}
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]*i%mod;
	}
	printf("%lld",f[n]);
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
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

