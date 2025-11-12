#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int T, n, a[MAXN], b[MAXN], c[MAXN], ra[MAXN], rb[MAXN], rc[MAXN], ans, cnta, cntb, cntc;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		ra[0] = rb[0] = rc[0] = ans = cnta = cntb = cntc = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] >= b[i] && a[i] >= c[i])
			{
				cnta++;
				ans += a[i];
				ra[++ra[0]] = a[i] - max(b[i], c[i]);
			}
			else if (b[i] >= c[i] && b[i] >= a[i])
			{
				cntb++;
				ans += b[i];
				rb[++rb[0]] = b[i] - max(a[i], c[i]);
			}
			else
			{
				cntc++;
				ans += c[i];
				rc[++rc[0]] = c[i] - max(a[i], b[i]);
			}
		}
		if (cnta > n / 2)
		{
			sort(ra + 1, ra + ra[0] + 1);
			for (int i = cnta - n / 2; i; i--)
			{
				ans -= ra[i];
			}
		}
		else if (cntb > n / 2)
		{
			sort(rb + 1, rb + rb[0] + 1);
			for (int i = cntb - n / 2; i; i--)
			{
				ans -= rb[i];
			}
		}
		else if (cntc > n / 2)
		{
			sort(rc + 1, rc + rc[0] + 1);
			for (int i = cntc - n / 2; i; i--)
			{
				ans -= rc[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}