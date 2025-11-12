#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int Mod=998244353;

char s[N];
int cnt[N], sum[N];
long long C[N][N], newdp[N][N], olddp[N][N], jc[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}

	sum[0]=cnt[0];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+cnt[i];

	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}

	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%Mod;

	newdp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		memcpy(olddp,newdp,sizeof(newdp));
		memset(newdp,0,sizeof(newdp));
		for(int j=0;j<=i;j++)
			for(int k=0;k<=min(sum[j],i);k++)
			{
				if(!olddp[j][k])
					continue;

				if(s[i+1]=='1')
				{
					(newdp[j][k] += olddp[j][k]) %= Mod;
					for(int p=0;p<=min(i-k,cnt[j+1]);p++)
						(newdp[j+1][k+p+1] += C[i-k][p]*C[cnt[j+1]][p]%Mod*jc[p]%Mod*(sum[j]-k)%Mod*olddp[j][k]) %= Mod;
				}
				else
				{
					for(int p=0;p<=min(i-k,cnt[j+1]);p++)
					{
						long long mul=C[i-k][p]*C[cnt[j+1]][p]%Mod*jc[p]%Mod*olddp[j][k]%Mod;
						(newdp[j+1][k+p+1] += mul*(sum[j+1]-k-p)) %= Mod;
						(newdp[j+1][k+p] += mul) %= Mod;
					}
				}
			}
	}

	long long ans=0;
	for(int j=0;j<=n-m;j++)
		(ans += newdp[j][sum[j]]*jc[n-sum[j]]) %= Mod;
	printf("%lld\n",(ans%Mod+Mod)%Mod);
	return 0;
}