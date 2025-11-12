#include<bits/stdc++.h>
using namespace std;
int n,m,dp[505][505],x[505],s1[505],t;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			s1[t++]=i;
		}
	}
	if(t>n)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;		
	}
	sort(x,x+n);
	t=2;
	if(s[0]=='1')
	{
		for(int i=0;i<n;i++)
		{
			if(x[i]!=0)
			{
				if(dp[0][i-1]==0)dp[0][i]=1;
				else
				{
					dp[0][i]=dp[0][i-1]*t%998244353;
					t++;
				}
			}
			else
			{
				dp[0][i]=0;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i>j||s1[i]>x[j]+i+1||s[j]=='0')
			{
				dp[i][j]=(dp[i][j-1]*(j-1))%998244353;
			}
			else
			{
				dp[i][j]=(dp[i-1][j-1]*(j-1))%998244353+(dp[i][j-1]*(j-1))%998244353;
			}
		}	
	}
	int ans=0;
	for(int i=m-1;i<n;i++)
	{
		ans=(ans+dp[i][n-1])%998244353;
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
