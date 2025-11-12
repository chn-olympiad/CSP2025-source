#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

const ll N = 1e5 + 5;

int n, cnt[5];
ll a[N][5], ans;
bool vis[N];
struct node
{
	ll val;
	int id, t;
	const friend bool operator<(const node &lhs, const node &rhs) { return lhs.val < rhs.val; }
};
priority_queue<node> q;

void init() {}

namespace brute_force
{
	const ll N1 = 105;
	ll f[2][N1][N1][N1];
	void dfs1(int now, ll sum)
	{
		if (now == n + 1)
		{
			ans = max(ans, sum);
			return;
		}
		for (int i = 1; i <= 3; ++i)
		{
			if (cnt[i] >= (n >> 1))
				continue;
			++cnt[i];
			dfs1(now + 1, sum + a[now][i]);
			--cnt[i];
		}
	}
	void solve1()
	{
		dfs1(1, 0);
		cout << ans << endl;
	}
	void solve2()
	{
		for (int x = 0; x <= (n >> 1); ++x)
		{
			for (int y = 0; y <= (n >> 1); ++y)
			{
				for (int z = 0; z <= (n >> 1); ++z)
					f[1][x][y][z] = f[0][x][y][z] = 0;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int x = 0; x <= (n >> 1); ++x)
			{
				for (int y = 0; y <= (n >> 1); ++y)
				{
					for (int z = 0; z <= min(n - x - y, n >> 1); ++z)
					{
						if (x + y + z > n)
							continue;
						f[i & 1][x][y][z] = 0;
						if (x)
							f[i & 1][x][y][z] = max(f[i & 1][x][y][z], f[i & 1 ^ 1][x - 1][y][z] + a[i][1]);
						if (y)
							f[i & 1][x][y][z] = max(f[i & 1][x][y][z], f[i & 1 ^ 1][x][y - 1][z] + a[i][2]);
						if (z)
							f[i & 1][x][y][z] = max(f[i & 1][x][y][z], f[i & 1 ^ 1][x][y][z - 1] + a[i][3]);
						if (i == n && x + y + z == n)
							ans = max(ans, f[i & 1][x][y][z]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	int b[N];
	bool check3()
	{
		for (int i = 1; i <= n; ++i)
		{
			if (a[i][3]) return 0;
		}
		return 1;
	}
	void solve3()
	{
		for (int i = 1; i <= n; ++i)
			b[i] = i;
		sort(b + 1, b + n + 1, [](int x, int y)
			{ return a[x][1] - a[x][2] > a[y][1] - a[y][2]; });
		for (int i = 1; i <= n; ++i)
		{
			if (i <= (n >> 1))
				ans += a[b[i]][1];
			else
				ans += a[b[i]][2];
		}
		cout << ans << endl;
	}
}

void solve()
{
	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
			cin >> a[i][j];
	}
	if (n <= 10)
		return brute_force::solve1();
	if (n <= 200)
		return brute_force::solve2();
	if (brute_force::check3())
		return brute_force::solve3();
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; ++i)
	{
		vis[i] = 0;
		for (int j = 1; j <= 3; ++j)
			q.push({a[i][j], i, j});
	}
	while (q.size())
	{
		auto cur = q.top();
		q.pop();
		ll val = cur.val;
		int id = cur.id, t = cur.t;
		if (vis[id] || cnt[t] >= (n >> 1))
			continue;
		vis[id] = 1;
		++cnt[t];
		ans += val;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	// freopen("club.in", "r", stdin);
	// freopen("club.out", "w", stdout);
	int _ = 1;
	cin >> _;
	init();
	while (_--)
		solve();
	return 0;
}
/*
g++ club.cpp -std=c++14 -O2 -Wall -o club.exe
*/
/*
都高一了还切不出A
是不是想被单调队列了
是不是想退役了
*/