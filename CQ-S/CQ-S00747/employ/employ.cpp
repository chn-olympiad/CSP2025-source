//60min，我怎么这么菜/ll
#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
bool stt;
int f[N][N][N],n,m,s[N],a[N],cnt[N],sum[N],g[N][N],fac[N];
int getc(){char ch=getchar();while(ch!='0' && ch!='1')ch=getchar();return ch-'0';}
bool edd;
int main()
{
	cerr<<((&stt)-(&edd))/1024.0/1024<<"\n";
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)s[i]=getc();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	sum[0]=cnt[0];for(int i=1;i<=n;i++)sum[i]=cnt[i]+sum[i-1];
	f[0][0][cnt[0]]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)if(f[i][j][k])
		{
			if(j<n && s[j+1]==1)f[i][j+1][k]=(f[i][j+1][k]+f[i][j][k])%mod;
			if(j<n && s[j+1]==0)f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k])%mod;
			if(j<n && k)f[i+1][j+1][k-1]=(f[i+1][j+1][k-1]+1ll*f[i][j][k]*k)%mod;
		}
		for(int j=1;j<=cnt[i+1];j++)
		{
			for(int k=0;k<=n;k++)for(int l=0;l<=n;l++)g[k][l]=0;
			for(int k=0;k<=n;k++)for(int l=0;l<=n;l++)if(f[i+1][k][l])
			{
				g[k][l+1]=(g[k][l+1]+f[i+1][k][l])%mod;
				if(sum[i]+j-1-l<k)g[k][l]=(g[k][l]+1ll*f[i+1][k][l]*(k-(sum[i]+j-1-l)))%mod;
			}
			for(int k=0;k<=n;k++)for(int l=0;l<=n;l++)f[i+1][k][l]=g[k][l];
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
	{
		ans=(ans+1ll*f[i][n][0]*fac[sum[n]-sum[i]])%mod;
	}
	printf("%d\n",ans);
	return 0;
}