#include <iostream>
using namespace std;

int arr[500005];
int dp[1<<21];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=(1<<20);i++)
	{
		dp[i]=-1e9;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i]^=arr[i-1];
		dp[arr[i]]=max(dp[arr[i]],dp[arr[i]^k]+1);
		dp[arr[i]]=max(dp[arr[i]],dp[arr[i-1]]);
		ans=max(ans,dp[arr[i]]);
	}
	cout<<ans;
	return 0;
}
