#include<bits/stdc++.h>
#define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
const int mod=998244353;
const int N=509;
int f[N][N][N],g[N][N];
int dp[1<<18][19];
int n,m,p,a[N],s[N],b[N],sum[N];
int fac[N],inv[N];
int C(int x,int y)
{
	if(x<y)
	return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	filein("employ");
	fileout("employ");
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++)
	fac[i]=fac[i-1]*i%mod;
	for(int i=n;i>=1;i--)
	inv[i-1]=fac[i]*i%mod;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='1')
		a[i]=1;
		if(!a[i])
		p++;
	}
	if(m<0)
	{
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+1-a[i];
		sum[b[i]]++;
	}
	for(int i=1;i<=n;i++)
	sum[i]+=sum[i-1];
	f[0][0][0]=1;
	//位置，死亡数，已选择
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
			f[i][j+1][k]=f[i-1][j][k];
			continue;
		}
		//死
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(sum[j]>k)
				f[i][j+1][k+1]=(f[i][j+1][k+1]+f[i-1][j][k]*(sum[j]-k))%mod;
			}
		}
		//活
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<i;k++)
			{
				f[i][j][k]=(f[i][j][k]+f[i-1][j][k])%mod;
				//容斥
				if(sum[j]>k)
				f[i][j][k+1]=(f[i][j][k+1]+mod-f[i-1][j][k]*(sum[j]-k)%mod)%mod;
			}
		}
		// for(int j=0;j<i;j++)
		// {
		// 	for(int k=0;k<i;k++)
		// 	{
		// 		cout<<f[i][j][k]<<' ';
		// 	}
		// 	cout<<'\n';
		// }
		// cout<<'\n';
	}
	int ans=0;
	for(int j=0;j<=n-m;j++)
	{
		for(int k=0;k<=n;k++)
		{
			// cout<<j<<' '<<k<<' '<<f[n][j][k]<<'\n';
			ans=(ans+f[n][j][k]*fac[n-k])%mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}