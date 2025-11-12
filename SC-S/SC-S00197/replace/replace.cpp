#include <bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],f[N][N][N],C[N][N],jc[N],sum[N];char c[N];
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;b=(b>>1);
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)C[i][j]=1ll*jc[i]*qmi(jc[j],mod-2)%mod*qmi(jc[i-j],mod-2)%mod;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		int o;cin>>o;
		a[o]++;
	}
	sum[0]=a[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=i-j;k<=i;k++)
			{
				for(int b=0;b<=a[i-j];b++)
				{
					if(sum[i-j]-k+1+b<=0)continue;
					if(k<=b)break;
					f[i][j][k]=(f[i][j][k]+1ll*C[a[i-j]][b]*(sum[i-j-1]-k+1)%mod*f[i-1][j][k-1-b]%mod*C[i-k+b][b]%mod*jc[b]%mod)%mod;
				}
				if(j&&c[i]=='1')f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
				//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
			}
		}
	}
	int res=0;
	for(int i=m;i<=n;i++)
	{
		for(int j=n-i;j<=n;j++)
		{
			if(sum[n]-sum[n-i]==n-j)res=(res+1ll*jc[n-j]*f[n][i][j]%mod)%mod;
		}
	}
	cout<<(res+mod)%mod;
	return 0;
}