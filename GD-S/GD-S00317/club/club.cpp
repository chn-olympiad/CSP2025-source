#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, cnt;
int a[N][3], b[N], s[3];

void work()
{
	scanf("%d", &n);
	int ans = 0;
	s[0] = s[1] = s[2] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		int mx = max(a[i][0], max(a[i][1], a[i][2]));
		ans += mx;
		for (int j = 0; j < 3; j++) if (a[i][j] == mx) { s[j]++; break; }
	}
	for (int j = 0; j < 3; j++)
		if (s[j] > n / 2)
		{
			cnt = 0;
			for (int i = 1; i <= n; i++)
				if (a[i][j] >= a[i][(j + 1) % 3] && a[i][j] >= a[i][(j + 2) % 3])
					b[++cnt] = a[i][j] - max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]);
			sort(b + 1, b + cnt + 1);
			for (int i = 1; i <= s[j] - n / 2; i++) ans -= b[i];
		}
	printf("%d\n", ans);
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
