#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

const ll N = 505, P = 998244353;

int n, m, b[N];
ll ans;
bool a[N];

void init() {}

namespace brute_force
{
	int t[N];
	void solve1()
	{
		for (int i = 1; i <= n; ++i)
			t[i] = i;
		do
		{
			int cnt = 0, tot = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (cnt >= b[t[i]] || !a[i])
					++cnt;
				else
					++tot;
			}
			ans += tot >= m;
		} while (next_permutation(t + 1, t + n + 1));
		cout << ans << endl;
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		cin >> ch;
		a[i] = ch - 48;
	}
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	if (n <= 10)
		return brute_force::solve1();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int _ = 1;
	// cin >> _;
	init();
	while (_--)
		solve();
	return 0;
}
/*
g++ employ.cpp -std=c++14 -O2 -Wall -o employ.exe
*/
/*
摆烂了，就写一个n!吧
*/