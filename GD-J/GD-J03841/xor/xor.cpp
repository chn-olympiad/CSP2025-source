#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;

long long k, n, a[MAXN], dp[MAXN], pre[MAXN]; map <long long, vector <long long> > mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	mp[pre[0]].push_back(0);
	
	pre[1] = a[1]; mp[pre[1]].push_back(1);
	
	for (int i = 2; i <= n; i ++)
	{
		pre[i] = pre[i - 1] ^ a[i]; mp[pre[i]].push_back(i);
	}
	
	for (int i = 1; i <= n; i ++)
	{
		dp[i] = dp[i - 1];
		
		auto tmp = mp[pre[i] ^ k];
		
		long long t = 0;
		
		for (int j : tmp)
		{
			if (j < i)
			{
				t = max(t, dp[j] + 1);
			}
			else
			{
				break;
			}
		}
		
		dp[i] = max(dp[i], t);
	}
	
	cout << dp[n];
	
	return 0;
}
