#include<iostream> 
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s="#"+s;
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	vector<vector<int>>dp(n+1,vector<int>(1<<n,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			dp[i][j]=dp[i-1][j];
			int cnt=0;
			for(int k=0;k<n;k++)
			{
				if((j>>k)&1)
				{
					cnt++;
				}
			}
			if(s[i]=='1'&&cnt<=i)
			{
				for(int k=1;k<=n;k++)
				{
					if(((j>>(k-1))&1)==1&&p[k]>cnt-1)
					{
						dp[i][j]+=dp[i-1][j^(1<<(k-1))];
						dp[i][j]%=998244353;
					}
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<(1<<n);j++)
	{
		int cnt=0;
		for(int k=0;k<n;k++)
		{
			if((j>>k)&1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=dp[n][j];
			ans%=998244353;
		}
	}
	cout<<ans<<endl;
	return 0;
}
