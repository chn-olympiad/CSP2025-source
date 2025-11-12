#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
struct Node
{
	int id, pos, val;
} d[MAXN];
bool cmp(Node x, Node y)
{
	return x.val < y.val;
}
int t, n, a[MAXN][4], cnt, ans2, ans1, sum[10], flag[MAXN], last[MAXN][5];
bool A;
void solve2(int i, int back)
{
	if (flag[d[i].id] != 2)
	{
		last[d[i].id][++flag[d[i].id]] = i;
		return ;
	}
	if (sum[d[i].pos] >= n / 2)
	{
		solve2(last[d[i].id][back], back - 1);
		return ;
	}
	sum[d[i].pos]++;
	ans2 += d[i].val;
}
void solve1()
{
	for (int i = cnt; i >= 1; i--)
	{
		if (flag[d[i].id] != 0 || sum[d[i].pos] >= n / 2)
			continue;
		flag[d[i].id]++;
		sum[d[i].pos]++;
		ans1 += d[i].val;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		A = true;
		memset(flag, 0, sizeof(flag));
		memset(last, 0, sizeof(last)); 
		for (int i = 0; i <= cnt + 1; i++)
			d[i].id = d[i].pos = d[i].val = -1;
		cnt = ans1 = ans2 = sum[1] = sum[2] = sum[3] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				d[++cnt].id = i;
				d[cnt].pos = j;
				d[cnt].val = a[i][j];
				if (j != 1)
					if (d[cnt].val != 0)
						A = false;
			}
		sort(d + 1, d + cnt + 1, cmp);
		if (A)
		{
			int ans = 0, sum = 0;
			for (int i = cnt; i >= 1; i--)
				if (d[i].pos == 1)
				{
					ans += d[i].val;
					sum++;
					if (sum >= n / 2)
						break;
				}
			cout << ans << endl;
			continue;
		}	
		for (int i = 1; i <= cnt; i++)
			solve2(i, 2);
		memset(flag, 0, sizeof(flag));
		sum[1] = sum[2] = sum[3] = 0;
		solve1();
		cout << max(ans1, ans2) << endl;
	}
    return 0;
}

