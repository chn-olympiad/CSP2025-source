# include <cstdio>
# define int long long
# define mod 998244353
using namespace std;
int n,m,a[1007],c[1007],f[300007][27],cc[300007],sum;
int pop_c(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%2;
		x/=2;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char ch=' ';
		while(ch!='0'&&ch!='1') ch=getchar();
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=18)
	{
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++) cc[i]=pop_c(i);
		for(int i=0;i<(1<<n)-1;i++)
		for(int j=0;j<=n;j++)
		for(int k=1;k<=n;k++)
		{
			if(i&(1<<(k-1))) continue;
			int j1=j;
			if(c[k]<=j) j1++;
			else if(a[cc[i]+1]==0) j1++;
			f[i+(1<<(k-1))][j1]=(f[i+(1<<(k-1))][j1]+f[i][j])%mod;
		}
		for(int i=0;i<=n-m;i++) sum=(sum+f[(1<<n)-1][i])%mod;
		printf("%lld",sum);
		return 0;
	}
	if(n==m)
	{
		int pan=1;
		for(int i=1;i<=n;i++) if(a[i]==0) pan=0;
		for(int i=1;i<=n;i++) if(c[i]==0) pan=0;
		if(pan==0)
		{
			printf("0");
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld",ans);
		return 0;
	}
	if(m==1)
	{
		int ans=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				int p=ans;
				for(int j=1;j<=n-i+cnt;j++) p=p*j%mod;
				for(int j=1;j<=n;j++)
				{
					if(c[j]>=i) sum=(sum+p)%mod;
				}
				int q=0;
				for(int j=1;j<=n;j++) if(c[j]<i) q++;
				ans=ans*(q-(i-1-cnt))%mod;
			}
			else cnt++;
		}
		printf("%lld",sum);
		return 0;
	}
}
