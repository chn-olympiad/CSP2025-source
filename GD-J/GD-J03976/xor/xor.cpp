#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
int ans=0;
unsigned long long dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(dp[i]==k) ans++;
		else dp[i+1]=dp[i+1]^dp[i]; 
	}
	if(dp[n]==k) ans++;
	cout<<ans;
	return 0;
}
