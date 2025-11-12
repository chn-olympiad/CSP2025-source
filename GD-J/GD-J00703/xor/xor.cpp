#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+10;
ll a[maxn];
ll xo[maxn];
ll dp[maxn];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k;
	cin>>n>>k;
	unordered_map<ll, deque<int> > mp;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		xo[i] = xo[i-1] ^ a[i];
		mp[xo[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int expected = xo[i]^k;
		dp[i] = dp[i-1];
		for(auto j:mp[expected])
		{
			if(j>=i) break;
			dp[i] = max(dp[i], dp[j]+1);
			//debug: cout<<"dp["<<i<<"]´Ódp["<<j<<"]×ªÒÆ£»\n";
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
}
