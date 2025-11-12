#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m, cnt;
char s[maxn];
int p[maxn];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
	} 
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0' && m == n)
		{
			cout << 0 << '\n';
			return 0;
		}
		if(s[i] == '1') cnt++;
	}
	if(cnt == n && m < n) 
	{
		cout << 0 << '\n';
		return 0;
	}
	if(cnt == n)
	{
		ll ans = 1;
		for(int i = 1; i <= n; i++)
		{
			ans = ans * i % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}
