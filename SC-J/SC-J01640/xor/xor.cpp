#include<bits/stdc++.h>
using namespace std;
map<int, int>m;  
map<int, bool>legal;
int a[500005];
int prefix[500005];  //前缀异或和 
int max_p[500005]; 
int dp[500005];  
int n, k;
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	m[0] = 0;
	legal[0] = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		prefix[i] = prefix[i - 1] ^ a[i];
		if (legal[prefix[i] ^ k])
		{
			int goal = m[prefix[i] ^ k];
			dp[i] = dp[max_p[goal]] + 1;
		}
		legal[prefix[i]] = true;
		m[prefix[i]] = i;
		max_p[i] = dp[i] >= dp[max_p[i - 1]] ? i : max_p[i - 1];
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}