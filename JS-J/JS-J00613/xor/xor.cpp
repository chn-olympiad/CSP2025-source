#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N];
bool vis[N];
struct Space
{
	int l, r;
}b[N];

bool cmp(Space x, Space y)
{
	if (x.r - x.l != y.r -  y.l) return x.r - x.l < y.r - y.l;
	return x.l < y.l;
}

bool chk(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		if (vis[i]) return false;
	}
	return true;
}

void fill (int l, int r)
{
	for (int i = l; i <= r; ++i) vis[i] = true;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int cur = 0;
	for (int l = 1; l <= n; ++l)
	{
		int val = 0;
		for (int r = l; r <= n; ++r)
		{
			val ^= a[r];
			if (val == k)
			{
				b[++cur].l = l;
				b[cur].r = r;
			}
		}
	}
	sort(b + 1, b + cur + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= cur; ++i)
	{
		if (chk(b[i].l, b[i].r))
		{
			++cnt;
			fill(b[i].l, b[i].r);
		}
	}
	cout << cnt << endl;
	return 0;
}
