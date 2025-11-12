#include<stdio.h>
#include<algorithm>
typedef long long ll;
const ll mod=998244353;
char s[510];
int c[510],p[20];
ll dp[510][510],mul[510];
int t[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		int ans=0;
		do
		{
			int now=0;
			for(int i=1;i<=n;i++)
				if(s[i]=='1'&&i-now-1<c[p[i]])
					now++;
			if(now>=m)
				ans++;
		}while(std::next_permutation(p+1,p+1+n));
		printf("%d",ans);
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			t[c[i]]++;
		for(int i=1;i<=n;i++)
			t[i]+=t[i-1];
		mul[0]=1;
		for(int i=1;i<=n;i++)
			mul[i]=mul[i-1]*i%mod;
		int cnt=0;
		ll ans=0,x=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
			{
				ans=(ans+x*mul[n-cnt-1]%mod*(t[n]-t[i-1])%mod)%mod;
				cnt++;
				x=x*t[i-1]%mod;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
