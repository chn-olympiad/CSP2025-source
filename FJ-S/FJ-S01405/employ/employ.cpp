//orz Ending_Now23
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
constexpr int mod = 998244353;
bool specA = true, specB = true;
int n, m, c[510], f[510];
long long ans;
bitset<510> bs;

inline bool judge()
{
	int rejected = 0, accepted = 0;
	for (int i = 1; i <= n; i++)
	{
		if (rejected >= c[f[i]])
		{
			rejected++;
			continue;
		}
		if (bs[i] == false)
		{
			rejected++;
			continue;
		}
		accepted++;
	}
	return accepted >= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (m != n)
		specB = false;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		bs[i] = (ch == '1');
		if (bs[i] == false)
			specA = false;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i], f[i] = i;
	if (specB)
	{
		if (!specA)
			cout << 0;
		else
		{
			ans = 1;
			for (int i = 1; i <= n; i++)
			{
				ans *= i;
				ans %= mod;
			}
		}
	}
	else if (specA)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= mod;
		}
	}
	else
	{
		do
		{
			ans += judge();
		} while (next_permutation(f + 1, f + n + 1));
	}
	cout << ans;
}
