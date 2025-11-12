#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 600, mod = 998244353;
int n, m, c[N], p[N], ans;
string s;
inline void print()
{
	int mul = 1;
	for (int i = 2; i <= n; i++)
	{
		mul = mul * i % mod;
	}
	cout << mul << "\n";
}
bool check()
{
	int giveup = 0, now = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (giveup >= c[p[i]])
		{
			giveup++;
		}
		else if (s[now] == '1')
		{
			cnt++;
		}
		else
		{
			giveup++;
		}
		now++;
	}
//	cout << cnt << "\n";
	return cnt >= m;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		p[i] = i;
	}
	bool flag = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '0')
			flag = 0;
	}
	if (m == n)
	{
		print();
		return 0;
	}
	do
	{
		ans += check();
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
	return 0;
}
