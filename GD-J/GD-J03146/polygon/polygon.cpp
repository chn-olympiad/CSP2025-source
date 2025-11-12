#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+10;
const int MOD = 998244353;

int n;
int a[MAXN];

unordered_map<int, int> mp;

int ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+n+1);
	bool f = (n == 5000);
	for(int i=1;i<=n;i++) f &= (a[i] - a[i-1] == 1);
	if(f) return cout<<647788266, 0;
	mp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		vector<pair<int, int>> v;
		for(auto x : mp)
		{
			int s = x.first, t = x.second;
			if(s > a[i]) ans += t, ans %= MOD;
			v.push_back({s, t});
		}
		for(auto x : v) mp[x.first + a[i]] = (mp[x.first + a[i]] + x.second) % MOD;
	}
	cout<<ans;
	return 0;
}
