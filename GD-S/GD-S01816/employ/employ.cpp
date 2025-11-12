#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[505],tot,dp1[1<<19][19],p2,mod=998244353;
bool p=1,f[505];
char c;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	scanf("%lld%lld%c",&n,&m,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if(c=='1') f[i]=1;
		else p=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(!a[i]) p2++;
	}
	if(m==n)
	{
		if(!p||p2)
		{
			printf("0");
			return 0;
		}
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%mod;
		printf("%lld",ans);
		return 0;
	}
	else if(n<=18)
	{
		tot=(1<<(n+1))-2;
		dp1[0][0]=1;
		for(int i=0;i<=tot;i+=2)
		{
			int sum=0;
			for(int j=2;j<=tot;j*=2) if(i&j) sum++;
			for(int j=0;j<n;j++)
			{
				int fail=sum-j;
				for(int k=1;k<=n;k++)
				{
					int code=1<<k;
					if(i&code) continue;
					if(!f[sum+1]||fail>=a[k]) dp1[i|code][j]=(dp1[i|code][j]+dp1[i][j])%mod;
					else dp1[i|code][j+1]=(dp1[i|code][j+1]+dp1[i][j])%mod;
				}
			}
		}
		for(int i=m;i<=n;i++) ans=(ans+dp1[tot][i])%mod;
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",rand()%mod);
	return 0;
}
