#include<bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
char s[N];
int c[N],cnt,n,m,dp[2][N][N],o=0,jc[N],ans;
void Inc(int&x,int y)
{
	(x+=y)>=P? x-=P:0;
}
void Dec(int&x,int y)
{
	(x-=y)<0? x+=P:0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=jc[0]=1;i<=n;i++)
		jc[i]=1LL*jc[i-1]*i%P;
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),c[x]++;
	for(int i=1;i<=n;i++)
		c[i]+=c[i-1];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
			++cnt;
		else
		{
			memset(dp[!o],0,sizeof(dp[!o]));
			for(int j=0;j+cnt<=i;j++)
			{
				for(int k=j;k+cnt<=i;k++)
				{
					if(k<=c[j+cnt])
					{
						int w=1LL*dp[o][j][k]*(c[j+cnt]-k)%P;
						Inc(dp[!o][j+1][k+1],w);
						Dec(dp[!o][j][k+1],w);
					}
					Inc(dp[!o][j][k],dp[o][j][k]);
				}
			}
			o^=1;
		}
	}
	for(int i=0;i+cnt<=n-m;i++)
		for(int j=i;j+cnt<=n;j++)
			ans=(ans+1LL*dp[o][i][j]*jc[n-j])%P;
	printf("%d",ans);
}
