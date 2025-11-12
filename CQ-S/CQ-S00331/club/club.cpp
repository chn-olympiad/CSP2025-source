#include<bits/stdc++.h>
using namespace std;
struct CLUB
{
	long long a,b,c;
}C[105000];
long long t,n,dp[3][700][700],DP[55000],ans;
bool A,B;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		A=1;
		B=1;
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&C[i].a,&C[i].b,&C[i].c);
			if(C[i].c!=0)B=0;
			if(C[i].b!=0||C[i].c!=0)A=0;
		}
//		B=0;
		if(A)
		{
			priority_queue<long long>q;
			for(long long i=1;i<=n;i++)
			{
				q.push(C[i].a);
			}
			for(long long i=1;i<=n/2;i++)
			{
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);
			continue;
		}
		if(B)
		{
//			cout<<"------------------------------\n";
			for(long long j=1;j<=n/2;j++)
			{
				DP[j]=-1e18;
			}
			DP[0]=0;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=n/2;j>=0;j--)
				{
					DP[j]+=C[i].b;
					if(j>=1)DP[j]=max(DP[j],DP[j-1]+C[i].a);
				}
			}
			printf("%lld\n",DP[n/2]);
			continue;
		}
		for(long long j=0;j<=n/2;j++)
		{
			for(long long k=0;k<=n/2;k++)
			{
				dp[0][j][k]=-1e18;
				dp[1][j][k]=-1e18;
			}
		}
		dp[0][0][0]=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<=n/2&&j<=i;j++)
			{
				for(long long k=0;k<=n/2&&j+k<=i;k++)
				{
					if(i-j-k<=n/2&&i-j-k>0)
					{
						dp[i&1][j][k]=dp[(i+1)&1][j][k]+C[i].c;
					}
					if(j>0)dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i+1)&1][j-1][k]+C[i].a);
					if(k>0)dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i+1)&1][j][k-1]+C[i].b);
					ans=max(ans,dp[i&1][j][k]);
//					cout<<i<<" "<<j<<" "<<k<<" "<<dp[i&1][j][k]<<endl;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
