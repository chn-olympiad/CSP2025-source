#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, inf = 0x3f3f3f3f, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}, mod = 1e9 + 7;

int a[N], sum[N];

struct S {
	int x, y;
	bool operator < (const S & o) const {
		if (x == o.x)
		{
			return y > o.y;
		}
		return x > o.x;
	}
};

priority_queue <S> ok;

vector <S> ans[N];

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if ((sum[j] ^ sum[i - 1]) == k)
			{
				ok.push ((S){i, j});
			}
		}
	}
	int tot = 0;
	while (ok.size ())
	{
		S u = ok.top ();
		ok.pop ();
		for (int j = 1; j <= tot; j++)
		{
			if (ans[j][ans[j].size () - 1].y < u.x)
			{
				ans[j].push_back (u);
			}
		}
		ans[++tot].push_back (u);
	}
//	for (int i = 1; i <= tot; i++)
//	{
//		for (int j = 0; j < ans[i].size (); j++)
//		{
//			cout << (ans[i][j].x) << " " << ans[i][j].y << " | ";
//		}
//		cout << endl;
//	}
	int maxn = 0;
	for (int i = 1; i <= tot; i++)
	{
		maxn = max ((int)(maxn), (int)(ans[i].size ()));
	}
	cout << maxn;
	return 0;
}

/*
4 2
2 1 0 3

2

----------

4 3
2 1 0 3

2

----------

4 0
2 1 0 3

1
*/
