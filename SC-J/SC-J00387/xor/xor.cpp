#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long dp[1000];
int zero=0,one=0,ans=0;
int y()
{
	for(int i=0;i<n;i++)
	{
		if(!(dp[i]==1||dp[i]==0))
			return 0;
	}
	return 1;
}
int z()
{
	for(int i=0;i<n;i++)
	{
		if(!(dp[i]==1))
			return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=0;i<n;i++)
		cin>>dp[i];
	if(n==1&&n==2)
		cout<<n/2;
	if(y())
	{
	
	if(z())
	{
		cout<<n/2;
		return 0;
	}
		if(k=1)
		{
			ans=0;
			for(long long i=0;i<n;i++)
			{
				
				if(dp[i]==0)
				zero++;
				if(dp[i]==1)
				one++;
				if(zero!=0&&one!=0)
				{
				
					ans++;
					zero=0;
					one=0;
				}
				if(one==2)
				{
					one=0;
					zero++;
				}
			}
		}
		if(k==0)
		{
			ans=0;
			for(long long i=0;i<n;i++)
			{
				if(dp[i]==0)
				{
					ans++;
					zero=0;
					one=0;
				}
				if(dp[i]==1)
					one++;
				if(one==2)
				{
					ans++;
					one=0;
				}
			}
		}
//	cout<<1;
	cout<<ans;
	return 0;
	}
	
	return 0;
}
