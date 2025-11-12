#include<bits/stdc++.h>
#define int long long
#define MOD ((int) (998244353)) 
#define endl '\n'
#define Max ((int) (1e5 + 5))

using namespace std;

int n, m;
string s;

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			break;
		}
		cnt++;
	}
	if (cnt >= m)
	{
		int ans = 1;
		for (int i = 2; i <= n; i++)
		{
			ans = ((ans % MOD) * (i % MOD)) % MOD;
		}
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}

