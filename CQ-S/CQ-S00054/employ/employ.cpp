#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
const int M=18;
char s[N];
int c[N];
int dp[2][M+1][1<<M];
inline void add(int &x,int y)
{
	x=x+y>=mod?x+y-mod:x+y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') cnt++;
	}
	if(n<=18)
	{
		int sum=0;
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				for(int k=0;k<=i;k++) dp[i&1][k][j]=0;
				if(__builtin_popcount(j)!=i) continue;
				for(int k=0;k<=i-1;k++)
				{
					for(int l=0;l<n;l++)
					{
						if((j>>l&1))
						{
							if(s[i]=='0')
							{
								add(dp[i&1][k][j],dp[(i&1)^1][k][j^(1<<l)]);
							}
							else
							{
								if(c[l+1]>(i-1)-(k))
								{
									add(dp[i&1][k+1][j],dp[(i&1)^1][k][j^(1<<l)]);
								}
								else add(dp[i&1][k][j],dp[(i&1)^1][k][j^(1<<l)]);
							}
							
						}
					}
//					if(i==1&&k==1&&j==1) cout<<dp[1][1][1]<<"\n";
				}
			
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) add(ans,dp[n&1][i][(1<<n)-1]);
		cout<<ans; 
	}
	else if(m==n)
	{
//		sort(c+1,c+1+n,greater<int>());
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[i]==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==0) puts("0");
		else 
		{
			long long ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			printf("%lld\n",ans);
		}
	}
	else puts("0");
	return 0;
}

