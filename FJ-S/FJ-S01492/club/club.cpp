#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node {
	int a, b, c;
	int i1, i2, i3;
}d[N];

int num[5], t, n;

long long ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		ans = 0, num[1] = num[2] = num[3] = 0;
		priority_queue<int> q[5];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
			d[i].i1 = 1, d[i].i2 = 2, d[i].i3 = 3;
			if (d[i].a < d[i].b)
			{
				swap(d[i].i1, d[i].i2);
				swap(d[i].a, d[i].b);
			}
			if (d[i].b < d[i].c)
			{
				swap(d[i].i3, d[i].i2);
				swap(d[i].c, d[i].b);
			}
			if (d[i].a < d[i].b)
			{
				swap(d[i].i1, d[i].i2);
				swap(d[i].a, d[i].b);
			}
			ans += d[i].a;
			num[d[i].i1]++;
			q[d[i].i1].push(d[i].b - d[i].a);
		}
		for (int i = 1; i <= 3; i++)
		{
			while (num[i] > (n / 2))
			{
				ans += q[i].top();
				q[i].pop();
				num[i]--;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
