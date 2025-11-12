#include<cstdio>
using namespace std;
const long long mod=998244353;
long long i,j,k,l,n,m,s[1100],c[1100],cnt[1100],psum[1100],fac[1100],nfac[1100],f[1100][1100],g[1100][1100],ans,num;
long long power(long long a,long long b)
{
	long long k=a,ans=1;
	while(b)
	{
		if(b&1)
		ans=ans*k%mod;
		k=k*k%mod;
		b=b>>1;
	}
	return ans;
}
long long choose(long long n,long long m)
{
	return fac[n]*nfac[m]%mod*nfac[n-m]%mod;
}
main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	scanf("%1lld",&s[i]);
	for(i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	for(i=1;i<=n;i++)
	cnt[c[i]]++;
	psum[0]=cnt[0];
	for(i=1;i<=n;i++)
	psum[i]=psum[i-1]+cnt[i];
	fac[0]=1;
	for(i=1;i<=n;i++)
	fac[i]=fac[i-1]*i%mod;
	for(i=0;i<=n;i++)
	nfac[i]=power(fac[i],mod-2);
	m--;
	f[0][0]=1;
	for(i=1;i<=n*2;i++)
	{
		for(j=0;j<=i&&j<=m;j++)
		for(k=0;k<=j;k++)
		g[j][k]=0;
		for(j=0;j<=i&&j<=m;j++)
		for(k=0;k<=j;k++)
		if(f[j][k]>0)
		if(s[i]==0)
		{
			for(l=0;l<=cnt[i-j]&&l<=j-k;l++)
			g[j][k+l]=(g[j][k+l]+f[j][k]*choose(j-k,l)%mod*fac[l]%mod*choose(cnt[i-j],l))%mod;
		}
		else
		{
			if(psum[i-j-1]-(num-j+k)>0)
			for(l=0;l<=cnt[i-j]&&l<=j-k;l++)
			g[j][k+l]=(g[j][k+l]+f[j][k]*(psum[i-j-1]-(num-j+k))%mod*choose(j-k,l)%mod*fac[l]%mod*choose(cnt[i-j],l))%mod;
			g[j+1][k]=(g[j+1][k]+f[j][k])%mod;
		}
		if(s[i]==1)
		num++;
		for(j=0;j<=i&&j<=m;j++)
		for(k=0;k<=j;k++)
		f[j][k]=g[j][k];
	}
	ans=fac[n];
	for(i=0;i<=m;i++)
	ans=(ans-f[i][i]*fac[n-num]%mod+mod)%mod;
	printf("%lld",ans);
}
