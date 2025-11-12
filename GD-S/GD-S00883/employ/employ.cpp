#include<bits/stdc++.h>
using namespace std;
const int N=1009;
const int mod=998244353;
int n,m,c[N],f[19][1<<18][19]; char a[N];
void work(int &a,int b){a=(a+b)%mod;}
int power(long long a,long long b)
{
	long long ans=1,base=a;
	while(b)
	{
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;b>>=1;
	}
	return ans%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	if(n<=18)
	{
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<(1<<n);j++)
				for(int k=1;k<=n;k++)
					if(!(j&(1<<(k-1))))
					{
						int g=0; if(a[i]=='0') g=1;
						for(int u=0;u<min(i,c[k]);u++)
							work(f[i][j|(1<<(k-1))][u+g],f[i-1][j][u]);
						for(int u=c[k];u<i;u++)
							work(f[i][j|(1<<(k-1))][u+1],f[i-1][j][u]);
					}
		int ans=0;
		for(int u=0;u<=n-m;u++)
			work(ans,f[n][(1<<n)-1][u]);
		printf("%d",ans); 
	}
	else if(m==n)
	{
		long long jc=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0'||c[i]==0) 
				return !printf("0");
			jc=jc*i%mod;
		}
		int ans=jc%mod;
		return !printf("%d",ans);
	}
	else printf("0");
	return 0;
}
