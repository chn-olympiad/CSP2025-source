#include <bits/stdc++.h>
using namespace std;

int n;

struct node
{
	int x, y, z;
}a[100005];

bool cmp(node x, node y)
{
	if (x.x != y.x)
		return x.x > y.x;
	else if (x.y != y.y)
		return x.y > y.y;
	return x.z > y.z;
}

int cnt1, cnt2, cnt3, ans;
int f[205][105][105];

void dfs(int step, int cnt1, int cnt2, int sum)
{
	if (cnt1 > n / 2 || cnt2 > n / 2 || step - cnt1 - cnt2 > n / 2)
		return ;
	if (step > n)
	{
		if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt1 + cnt2 >= n / 2)
			ans = max(ans, sum);
		return ;
	}
	dfs(step + 1, cnt1 + 1, cnt2, sum + a[step].x);
	dfs(step + 1, cnt1, cnt2 + 1, sum + a[step].y);
	dfs(step + 1, cnt1, cnt2, sum + a[step].z);
}

void Main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	cnt1 = cnt2 = cnt3 = ans = 0;
	if (n <= 10)
		dfs(1, 0, 0, 0);
	else
	{
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (a[i].x > a[i].y)
			{
				if (cnt1 < n / 2)
					cnt1++, ans += a[i].x;
			}
			else
			{
				if (cnt2 < n / 2)
					cnt2++, ans += a[i].y;
			}
		}
		printf("%d\n", ans);
		return ;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
		Main();
	return 0;
}
