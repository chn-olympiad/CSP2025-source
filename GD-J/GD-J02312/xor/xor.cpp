#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
int dp[500001];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, now=0;
	scanf("%d %d", &n, &k);
	mp[0]=1;
	for(int i = 1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		now^=x;
		dp[i]=dp[i-1];
		int id = mp[now^k];
		if(id)
		{
			dp[i]=max(dp[i], dp[id-1]+1);
		}
		mp[now]=i+1;
	}
	cout << dp[n] << endl;
	return 0;
}
