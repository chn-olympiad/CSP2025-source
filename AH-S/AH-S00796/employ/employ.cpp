#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
#define int long long
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int mod=998244353,N=505;
int n,m;
char str[N];
int s[N],c[N];
namespace SOL
{

int f[(1<<18)+10][18];
void work()
{
	f[0][0]=1;
	for(int s=0;s<(1<<n);s++)
	{
		int sum=__builtin_popcount(s);
		for(int k=0;k<=sum;k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(s&(1<<(i-1))) continue;
				int ns=s|(1<<(i-1));
				if(k>=c[i]||!::s[sum+1]) f[ns][k+1]=(f[ns][k+1]+f[s][k])%mod;
				else f[ns][k]=(f[ns][k]+f[s][k])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans<<endl;
	exit(0);
}

}
namespace SOL2
{

int cnt[N];
int fac[N],inv[N];
int f[N],g[N];
int C(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int A(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[n-m]%mod;
}
void work()
{
	fac[0]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n;i++) cnt[c[i]]++;
	f[cnt[0]]=fac[cnt[0]];
	int sum=cnt[0];
	for(int i=1;i<=n;i++)
	{
		if(!cnt[i]) continue;
		for(int k=cnt[0];k<=sum;k++)
		{//front un
			int tp=k-i+1,tp2=sum+1-tp;
			if(k<i)
			{
				g[k]=(g[k]+f[k]*A(sum+1+cnt[i]-1,cnt[i]))%mod;
				continue;
			}
			for(int j=0;j<=cnt[i];j++)
			{//now un
				g[j+k]=(g[j+k]+C(cnt[i],j)*f[k]%mod*A(tp+j-1,j)%mod*A(tp2+cnt[i]-j-1,cnt[i]-j))%mod;
			}
		}
		sum+=cnt[i];
		for(int k=cnt[0];k<=sum;k++) f[k]=g[k],g[k]=0;
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+f[i])%mod;
	cout<<ans<<endl;
	exit(0);
}

}
namespace SOL3
{

void work()
{
	bool fg1=(*min_element(c+1,c+n+1)==0),fg2=(*min_element(s+1,s+n+1)==0);
	if(!fg1&&!fg2)
	{
		int fac=1;
		for(int i=1;i<=n;i++) fac=fac*i%mod;
		cout<<fac<<endl;
	}
	else cout<<0<<endl;
	exit(0);
}

}
signed main()
{
#if __MY_TEST__
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	n=read(),m=read();
	cin>>str+1;
	for(int i=1;i<=n;i++) s[i]=str[i]-'0';
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=18) SOL::work();
	if(m==n) SOL3::work();
	if(*min_element(s+1,s+n+1)==1) SOL2::work();/*
	if(m==1) SOL4::work();*/
}

