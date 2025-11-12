#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool f = true;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] != '0')
			f = false;
	}
	if(m == n)
		cout << (f ? 1 : 0) << endl;
	if(m == 1)
	{
		int ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * n % 998244353;
		cout << ans << endl;
	}
	return 0;
}