#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const long long mod=998244353;
long long n,m,c[510],fac[510];
string s;
namespace pts_20
{
	long long f[300000][20];
	long long DP()
	{
		f[0][0]=1;
		for(long long i=0;i<(1ll<<n);i++)
		{
			long long tot=__builtin_popcountll(i);
			for(long long tar=1;tar<=n;tar++)
				if(!(i&(1ll<<(tar-1))))
					for(long long j=0;j<=tot;j++)
					{
						bool check=((tot-j)<c[tar])&&(s[tot+1]=='1');
						f[i|(1ll<<(tar-1))][j+check]=(f[i|(1ll<<(tar-1))][j+check]+f[i][j])%mod;
					}
		}
		long long ans=0;
		for(long long i=m;i<=n;i++) ans=(ans+f[(1ll<<n)-1][i])%mod;
		return ans;
	}
}
namespace pts_44
{
	long long f[110][110][110];
	long long DP()
	{
		for(long long i=1;i<=n;i++)
		{
			if(s[1]=='1')
			{
				if(c[i]==0) f[1][0][i]=1;
				else f[1][1][i]=1;
			}
			else f[1][0][i]=1;
		}
		for(long long i=2;i<=n;i++)
			for(long long j=0;j<i;j++)
			{
				long long sum=0;
				for(long long k=1;k<=n;k++) sum=(sum+f[i-1][j][k])%mod;
				for(long long k=1;k<=n;k++)
				{
					bool check=((i-1-j)<c[k])&&(s[i]=='1');
					f[i][j+check][k]=(f[i][j+check][k]+((sum-f[i-1][j][k])%mod+mod)%mod)%mod;
				}
			}
		long long ans=0;
		for(long long i=m;i<=n;i++)
			for(long long j=1;j<=n;j++)
				ans=(ans+f[n][i][j])%mod;
		return ans;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s.insert(s.begin(),'0');
	fac[0]=1;
	for(long long i=1;i<=n;i++) cin>>c[i],fac[i]=fac[i-1]*i%mod;
	if(n<=18)
	{
		cout<<pts_20::DP()<<endl;
		return 0;
	}
	else
	{
		bool checkA=1;
		for(long long i=1;i<=n;i++)
			if(s[i]!='1')
			{
				checkA=0;
				break;
			}
		if(checkA)
		{
			return 0;
		}
		else if(m==n)
		{
			cout<<0<<endl;
			return 0;
		}
		else if(m==1)
		{
			return 0;
		}
	}
}