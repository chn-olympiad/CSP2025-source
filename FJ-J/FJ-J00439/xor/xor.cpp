#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, k, a[N], t[N], res, cnt;
struct Node
{
	int x, y;
} p[N];

void dfs(int l, int r, int len)
{
	if (r - l + 1 < len) return;
	int cnt = 0;
	for (int i = l; i <= r - len + 1; i ++ )
	{
		if ((t[i + len - 1] ^ t[i - 1]) == k)
		{
			p[ ++ cnt].x = i;
			p[cnt].y = i + len - 1;
			i = i + len - 1;
			res ++ ;
		}
	}
	if (cnt == 0) return;
	dfs(l, p[1].x - 1, len + 1);
	for (int i = 1; i < cnt; i ++ )
	{
		dfs(p[i].y + 1, p[i + 1].x - 1, len + 1);
	}
	dfs(p[cnt].y + 1, r, len + 1);
}

bool cmp(Node l, Node r)
{
	if (l.y != r.y) return l.y < r.y;
	else return l.x < r.x;
}

void solve()
{
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = i; j <= n; j ++ )
		{
			if ((t[j] ^ t[i - 1]) == k)
			{
				p[ ++ cnt].x = i;
				p[cnt].y = j;
			}
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	int now = 0;
	for (int i = 1; i <= cnt; i ++ )
	{
		if (p[i].x > now) res ++ , now = p[i].y;
	}
	cout << res << endl;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
	}
	t[1] = a[1];
	for (int i = 2; i <= n; i ++ ) t[i] = t[i - 1] ^ a[i];
	if (n <= 1000) solve();
	else
	{
		dfs(1, n, 1);
		cout << res << endl;
	}
	return 0;
}
