#include<iostream>
using namespace std;
int n,a[100001],ans1=0;
long long k;
int dp[100001];
bool pd(int x,int y)
{
	long long ans=a[x]^a[y];
	for(int i=x+1;i<=y;i++)
	{
		ans=ans^a[i];
	}
	if(ans==k)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==k)
	{
		dp[1]=1;
	}
	else dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==k)
		{
			dp[i]=dp[i-1]+1;
		}
		else
		{
			dp[i]=dp[i-1];
			for(int j=1;j<i;j++)
			{
				for(int z=1;z<j;z++)
				{
					if(pd(z,j))
					{
						for(int x=1;x<j;x++)
						{
							dp[i]=max(dp[x]+1,dp[i]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		ans1=max(ans1,dp[i]);
	}
	cout<<ans1<<endl;
	return 0;
}
