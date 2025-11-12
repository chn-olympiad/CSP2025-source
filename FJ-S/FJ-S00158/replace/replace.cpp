#include<bits/stdc++.h>
using namespace std;
int n,q,dp[5000005];
map<string,string> mp;
bool vis[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string s,t;
		cin >> s >> t;
		mp[s] = t;
	}
	while(q--)
	{
		string s,t;
		cin >> s >> t;
		s = " "+s;
		t = " "+t;
		if(s.size() != t.size()) 
		{
			cout << "0\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0] = vis[0] = 1;
		for(int i = 1;i < s.size();i++) vis[i] = vis[i-1]&(s[i] == t[i]);
		for(int i = 1;i < s.size();i++)
		{
			if(s[i] == t[i])
			{
				dp[i] = dp[i-1];
			}
			for(int j = 1;j <= i;j++)
			{
				if(mp[s.substr(j,i-j+1)] == t.substr(j,i-j+1) && vis[j-1])
				{
					dp[i] += dp[j-1];
				}
			}
		}
		cout << dp[s.size()-1] << "\n";
	}
	return 0;
}

