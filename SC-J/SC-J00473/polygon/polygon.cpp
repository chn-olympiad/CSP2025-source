#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

constexpr long long MOD=998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	vector<int>len(n+1);
	vector<vector<int>>c(n+1,vector<int>(n+1,0));
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j!=0)
			{
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				c[i][j]%=MOD;
			}
			else
			{
				c[i][j]=1;
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
		maxn=max(maxn,len[i]);
	}
	vector<vector<int>>dp(maxn+2,vector<int>(3,0));
	dp[0][0]=1;
	sort(len.begin()+1,len.end());
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		ans+=c[n][i];
		ans%=MOD;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=len[i];j++)
		{
			ans-=dp[j][2];
			ans=(ans%MOD+MOD)%MOD;
		}
		for(int j=maxn-len[i]+1;j>=0;j--)
		{
			for(int k=0;k<=2;k++)
			{
				dp[j+len[i]][min(2,k+1)]+=dp[j][k];
				dp[j+len[i]][min(2,k+1)]%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
  It's been a year since the last CSP test.Last year I only got 250pts in CSP-J and 150pts in 
CSP-S.For me,it's a bad result.But now my goal is only AK.
  I started to learn OI three years ago.Manytimes I got very bad scores,including the CSP test
last year.I wanted to give up.But I remember my goal.It really encouraged me a lot.I will never
forget what difficulties I faced during these years.I will keep on OI,although I'm going to be
AFO next year.
  Hope my hard work can be paid off.
*/