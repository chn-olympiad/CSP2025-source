#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],ans,b[N],c[N],sum[N],cnt,now;
char str[N];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)a[i]=read(),++sum[a[i]];
	for(int i=1;i<=n;i++)if(str[i]=='1')++cnt;
	if(n>10)
	{
		cnt=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++)if(str[i]=='1')b[++cnt]=i;
		for(int i=0;i<(1<<cnt);i++)
		{
			now=0;
			for(int j=1;j<=cnt;j++)
				if(i>>(j-1)&1)
					c[++now]=b[j];
			if(now!=m)continue;
			int res=1;
			for(int i=now;i>=1;i--)
			{
			if(sum[n]-sum[c[i]-1-(i-1)]-(now-i)<=0)
			{
				res=0;
				break;
			}
			res=res*(sum[n]-sum[c[i]-1-(i-1)]-(now-i))%mod;
			}
			ans=(ans+res)%mod;
			}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=i;
	do
	{
		int now=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0'||now>=a[b[i]])++now;
			else ++cnt;
		}
		if(cnt>=m)++ans;
	}while(next_permutation(b+1,b+n+1));
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
