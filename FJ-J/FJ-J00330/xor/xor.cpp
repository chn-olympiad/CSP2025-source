#include<bits/stdc++.h>
using namespace std;
int sum[500005];
struct edge
{
	int left;
	int right;
}s[4*500005];
int cnt = 0;
bool cmp(edge a,edge b)
{
	return (a.left==b.left?a.right<b.right:a.left<b.left);
}
int dp[4*500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	int n,k;
 	cin >> n >> k;
 	for(int i = 1;i<=n;i++)
 	{
 		cin >> sum[i];
 		sum[i]^=sum[i-1];
 	}
 	for(int i = 1;i<=n;i++)
 	{
 		for(int j = i;j<=n;j++)
 		{
 			if((sum[j]^sum[i-1])==k)
 			{
 				s[++cnt].left = i;
 				s[cnt].right = j;
 			}
 		}
 	}
 	sort(s+1,s+cnt+1,cmp);
 	int ans = 0;
 	for(int i = 1;i<=cnt;i++)
 	{
 		for(int j = i-1;j>=1;j--)
 		{
 			if(s[j].right<s[i].left&&s[j].left<s[i].left&&s[j].right<s[i].right&&s[j].left<s[i].left)
 			{
 				dp[i]=max(dp[j],dp[i]);
 			}
 		}
 		dp[i]++;
		ans = max(dp[i],ans);
 	}
 	cout << ans;
	return 0;
}

