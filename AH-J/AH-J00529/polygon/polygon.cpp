#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int mod=998244353;
long long qpow(int x,int k)
{
	if(k==0) return 1;
	if(k==1) return x%mod;
	if(k%2) return qpow(x,k-1)*x%mod;
	long long t=qpow(x,k/2)%mod;
	return t*t%mod;
}
int a[5005];
int m,k;
long long f[5005][5005];
long long dfs(int p,int s)
{
	if(s>k) return qpow(2,m-p+1);
	if(p>m) return 0;
	if(f[p][s]!=-1) return f[p][s];
	f[p][s]=(dfs(p+1,s+a[p])+dfs(p+1,s))%mod;
	return f[p][s];
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n=read();
	bool pd=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(i!=1 && a[i]!=a[i-1]) pd=0;
	}
	sort(a+1,a+n+1);
	if(n==3){write(a[1]+a[2]>a[3]);return 0;}
	if(pd){write(((qpow(2,n)-n+mod)%mod-n*(n-1)/2%mod-1+mod)%mod);return 0;};
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		k=a[i];
		m=i-1;
		memset(f,-1,sizeof f);
		ans=(ans+dfs(1,0))%mod;
	}
	write(ans);
	return 0;
}
