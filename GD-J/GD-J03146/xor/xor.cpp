#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;

int n, k;
int a[MAXN];
int p[MAXN];

int l[MAXN];
int dp[MAXN];

unordered_map<int, vector<int>> mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i], p[i] = p[i-1] ^ a[i];
	mp[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		dp[i] = dp[i-1];
		l[i] = l[i-1];
		for(auto q : mp[p[i]^k])
		{
			if(q < l[i-1]) continue;
			if(dp[q] + 1 > dp[i])
			{
				dp[i] = dp[q] + 1;
				l[i] = i;
			}
		}
		mp[p[i]].push_back(i);
	}
	cout<<dp[n];
	return 0;
}
