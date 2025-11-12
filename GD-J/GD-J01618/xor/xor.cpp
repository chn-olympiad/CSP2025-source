#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500007];
int pos[1048583];
int nxt[500007];
int presum[500007];
void init()
{
	for(int i=1;i<=n;i++)
		presum[i] = presum[i-1] ^ a[i];
	memset(nxt,-1,sizeof(nxt));
	memset(pos,-1,sizeof(pos));
	for(int i=n;i>=1;i--)
	{
		if(pos[k^presum[i-1]]!=-1)
			nxt[i] = pos[k^presum[i-1]];
		if(a[i]==k)
			nxt[i] = i;
		pos[presum[i]] = i;
	}
//	for(int i=1;i<=n;i++)
//		cout<<nxt[i]<<" ";
}
int dp[500007][2];
signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init();
	for(int i=1;i<=n;i++)
	{
//		dp[i] = max(dp[i],dp[i-1]);
//		dp[nxt[i+1]] = max(dp[nxt[i+1]],dp[i]+1);
		dp[i][0] = max(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
		dp[i][1] = max(dp[i][1],dp[i][0]);
		dp[nxt[i]][1] = max(dp[nxt[i]][1],dp[i][0]+1);
	}
	cout<<dp[n][1]<<endl;
	return 0;
} 
