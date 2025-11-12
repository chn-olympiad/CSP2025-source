#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n, m, c[505], id[505];
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		id[i] = i;
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
		if (s[i] != '1')
		{
			flag = false;
			break;
		}
	if (flag)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (c[i] == 0) cnt++;
		ll mul = 1;
		for (int i = 2; i <= n - cnt; i++)
			mul = (mul * i) % mod;
		cout << mul << endl;
		return 0;
	}
	if (m == 1)
	{
		int pos;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
			{
				pos = i + 1;
				break;
			}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (c[i] >= pos) cnt++;
		ll mul = 1;
		for (int i = 2; i <= n - 1; i++)
			mul = (mul * i) % mod;
		mul = (mul * cnt) % mod;
		cout << mul << endl;
		return 0;
	}
	ll ans = 0;
	do
	{
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cnt0 >= c[id[i]])
			{
				cnt0++;
				continue;
			}
			if (s[i - 1] == '0') cnt0++;
			else cnt1++;
		}
		if (cnt1 >= m) ans = (ans + 1) % mod;
	} while (next_permutation(id + 1, id + n + 1));
	cout << ans << endl;
	return 0;
}
