#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

struct Tree {
	int l, r, val;
}tree[4 * N];

int d[N], n, m, k, ans;

inline void bt(int k, int l, int r)
{
	tree[k].l = l;
	tree[k].r = r;
	if (l == r)
	{
		tree[k].val = d[l];
		return ;
	}
	int mid = (l + r) >> 1;
	bt(2 * k, l, mid);
	bt(2 * k + 1, mid + 1, r);
}

inline int que(int k, int l, int r)
{
	if (l <= tree[k].l && tree[k].r <= r)
	{
		return tree[k].val;
	}
	int mid = (tree[k].l + tree[k].r) >> 1;
	int s = 0;
	if (l <= mid)
	{
		s ^= que(2 * k, l, r);
	}
	if (mid < r)
	{
		s ^= que(2 * k + 1, l, r);
	}
	return s;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
	}
	bt(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
//			printf("%d %d %d\n", i, j, que(1, i, j));
			if (que(1, i, j) == m)
			{
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
