#include <bits/stdc++.h>
using namespace std;

int x[500010], cnt;

struct Xor
{
	int l, r;
}p[10000010];

bool cmp(Xor a, Xor b)
{
	if (a.r != b.r) return a.r < b.r;
	else return a.l < b.l;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0, t = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++)
	{
		int m = x[i];
		if (m == k)
		{
			cnt++;
			p[cnt].l = i;
			p[cnt].r = i;
		}
		for (int j = i + 1; j <= n; j++)
		{
			m = (m xor x[j]);
			if (m == k)
			{
				cnt++;
				p[cnt].l = i;
				p[cnt].r = j;
			}
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) if (p[i].l > t) ans++, t = p[i].r;
	cout << ans;
	return 0;
} 
