#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[200010],an[200010],dp[200010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k){
			an[i]=1;
			continue;
		}
		int ak=a[i];
		int j=i+1;
		for(;j<=n;j++)
		{
			ak^=a[j];
			if(ak==k)
			{
				break;
			}
		}
		if(ak==k)an[i]=j-i+1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if(an[i]==0)continue;
		dp[i+an[i]-1]=max(dp[i+an[i]-1],dp[i-1]+1);
	}
	cout<<dp[n];
	return 0;
}
