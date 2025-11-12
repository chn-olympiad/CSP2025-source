#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int mod=998244353;
const int N=505;
int n,m;
string s;
int c[N];
int cnt[N],pre[N];
ll f[N][N][N],C[N][N],fac[N]{1};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i],cnt[c[i]]++;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+cnt[i];
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		//选了j个>=k的
		for(int j=0;j<=n;j++)
		{
			//k-1个没过
			for(int k=1;k<=n;k++)
			{
				//你不关心>=k的具体怎么选
				if(s[i]=='0')
				{
					//>=k+1的没过
					//枚举有几个==k的
					for(int l=0;l<=j;l++)
					{
						if(cnt[k]<l)break;
						f[i][j-l+1][k+1]=(f[i][j-l+1][k+1]+f[i-1][j][k]*C[j][l]%mod*fac[l]%mod*C[cnt[k]][l]%mod)%mod;
					}
					//<=k的没过,选一个<=k要关心
					for(int l=0;l<=j;l++)
					{
						if(cnt[k]<l)break;
						if(pre[k]-(i-1-(j-l))<=0)continue;
						f[i][j-l][k+1]=(f[i][j-l][k+1]+f[i-1][j][k]*(pre[k]-(i-1-(j-l)))%mod)%mod;
					}
				}
				else
				{
					//选一个>=k的
					if((n-pre[k-1]-j)>=1)
					f[i][j+1][k]=(f[i][j+1][k]+f[i-1][j][k])%mod;
					//other case
					{
						for(int l=0;l<=j;l++)
						{
							if(cnt[k]<l)break;
							if(pre[k]-(i-1-(j-l))<=0)continue;
							f[i][j-l][k+1]=(f[i][j-l][k+1]+f[i-1][j][k]*C[j][l]%mod*C[cnt[k]][l]%mod*fac[l]%mod*(pre[k]-(i-1-(j-l)))%mod)%mod;
						}
					}
				}
			}
		}
	}
	ll res=0;
	for(int k=0;k<=n-m;k++)
	{
		for(int j=0;j<=n;j++)
		{
			res=(res+f[n][j][k+1]*fac[j]%mod)%mod;
		}
	}
	printf("%lld\n",res);
}