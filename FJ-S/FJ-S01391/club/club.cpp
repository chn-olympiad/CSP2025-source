#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, ans;
int a[100005][5];
void dfs(int k, int sum, int t1, int t2, int t3)
{
	if (k == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	int mid = n / 2;
	if (t1 < mid)
		dfs(k + 1, sum + a[k][1], t1 + 1, t2, t3);
	if (t2 < mid)
		dfs(k + 1, sum + a[k][2], t1, t2 + 1, t3);
	if (t3 < mid)
		dfs(k + 1, sum + a[k][3], t1, t2, t3 + 1);
}
void slove1()
{
//	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	dfs(1, 0, 0, 0, 0);
	cout << ans << '\n';
}
struct QWQ
{
	int a, id;
};
bool cmp1(QWQ a, QWQ b)
{
	if (a.a == b.a)
		return a.id < b.id;
	else
		return a.a > b.a;
}
struct W
{
	QWQ a[5];
	void mk(int a1, int a2, int a3)
	{
		a[1].a = a1;
		a[2].a = a2;
		a[3].a = a3;
		a[1].id = 1;
		a[2].id = 2;
		a[3].id = 3;
		sort(a + 1, a + 4, cmp1);
	}
	int get(int id)
	{
		return this->a[id].a;
	}
} aq[100005];
bool cmp2(W a, W b)
{
	if(a.get(1) == b.get(1))
	{
		if (a.get(2) == b.get(2))
		{
			return a.get(3) > b.get(3);
		}
		else
		{
			return a.get(2) > a.get(2);
		}
	}
	else
	{
		return a.get(1) > a.get(1);
	}
}
int tot[5];
void slove2()
{
//	cin >> n;
	tot[1] = tot[2] = tot[3] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		aq[i].mk(a1, a2, a3);
	}
	sort(aq + 1, aq + 1 + n, cmp2);
	int mid = n / 2;
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (tot[aq[i].a[j].id] < mid)
			{
				tot[aq[i].a[j].id]++;
				ans += aq[i].get(j);
				break;
			}
		}
	}
	cout << ans << '\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n <= 10)
			slove1();
		else
			slove2();
	}
	return 0;
}
//for (int i = 1; i <= n; i++)
//	for (int j = 1; j <= 3; j++)
//		dp[i][j].clear();
//for (int i = 1; i <= n; i++)
//	cin >> a[i][1] >> a[i][2] >> a[i][3];
//int mid = n / 2;
//for (int i = 1; i <= n; i++)
//{
//	for (int j = 1; j <= 3; j++)
//	{
//		int w = dp[i - 1][j].w;
//		dp[i][j].w = w;
//		for (int k = 1; k <= 3; k++)
//		{
//			if (dp[i - 1][k].tot[j] >= mid)
//				continue;
//			if (a[i][j] + dp[i - 1][k].w > dp[i][j].w)
//			{
//				dp[i][j].w = a[i][j] + dp[i - 1][k].w;
//				for (int kk = 1; kk <= 3; kk++)
//				{
//					if (kk == j)
//						dp[i][j].tot[kk] = dp[i - 1][k].tot[kk] + 1;
//					else
//						dp[i][j].tot[kk] = dp[i - 1][k].tot[kk];
//				}
//			}
//		}
//	}
//}
//cout << max(max(dp[n][1].w, dp[n][2].w), dp[n][3].w) << '\n';
