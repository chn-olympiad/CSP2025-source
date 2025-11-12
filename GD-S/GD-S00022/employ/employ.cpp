#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,m,c[505],f[300005][20];
char ss[505];
void read(long long &x)
{
	x=0;
	char ch=0;
	while('0'>ch||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
long long num(long long o)
{
	long long k=0;
	while(o)
	{k++;
		o-=o&-o;
	}
	return k;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	scanf("%s",ss+1);
	long long u=0;
	for(int i=1;i<=n;i++) read(c[i]),u+=c[i]==0;
	long long tt=0;
	for(int i=1;i<=n;i++)tt+=ss[i]=='1';
	if(tt<m) 
	{
		printf("0\n");
		return 0;
	}
	if(u&&m==n) 
	{
		printf("0\n");
		return 0;
	}
	if(m==n)
	{
		long long o=1;
		for(int i=1;i<=n;i++)o=o*i%mod;
		printf("%lld\n",o);
		return 0;
	}
	long long ans=0;
	f[0][0]=1;
	for(int s=0;s<(1ll<<n);s++)
	{
		long long t=num(s);
		for(int k=1;k<=n;k++)
		{
			if(!((s>>(k-1))&1))
			{
				for(int j=0;j<=n;j++)
				{
					(f[s|(1<<(k-1))][j+((c[k]<=j)||ss[t+1]=='0')]+=f[s][j])%=mod;
				}
			}
		}
	}
	
	for(int i=0;i<=n-m;i++)ans+=f[(1<<n)-1][i];
	
	printf("%lld\n",ans);
	return 0;
}
