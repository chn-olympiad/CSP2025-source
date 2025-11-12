#include <bits/stdc++.h>

#define x first
#define y second
#define mk make_pair
#define int long long

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> PII;

int T, n, a[N][3], cnt[5], k[N][2], maxn;
priority_queue<PII, vector<PII>, greater<PII> > q[3];
priority_queue<int, vector<int>, greater<int> > pq1, pq2;
int ttt[N];

void dfs(int d, int cnt1, int cnt2, int cnt3, int s)
{
	if (d == n + 1)
	{
		maxn = max(maxn, s);
		return;
	}
	if (cnt1 < n / 2) dfs(d + 1, cnt1 + 1, cnt2, cnt3, s + a[d][0]);
	if (cnt2 < n / 2) dfs(d + 1, cnt1, cnt2 + 1, cnt3, s + a[d][1]);
	if (cnt3 < n / 2) dfs(d + 1, cnt1, cnt2, cnt3 + 1, s + a[d][2]);
}

void solve()
{
	cnt[0] = cnt[1] = cnt[2] = 0;
	int res = 0, flag = 0, flag2 = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 0; j < 3; j ++ )
		{
			scanf("%lld", &a[i][j]);
			if (j == 1 && a[i][j]) flag = 1;
			if (j == 2 && a[i][j]) flag2 = 1;
		}
	}
	if (n <= 10)
	{
		maxn = 0;
		dfs(1, 0, 0, 0, 0);
		cout << maxn << endl;
		return;
	}
	if (flag && flag2)
	{
		for (int i = 1; i <= n; i ++ ) ttt[i] = a[i][0];
		sort(ttt + 1, ttt + n + 1);
		int sum = 0;
		for (int i = 1; i <= n / 2; i ++ ) sum += ttt[n - i + 1];
		cout << sum << endl;
		return;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i][0] >= a[i][1] && a[i][1] >= a[i][2]) k[i][0] = 0, k[i][1] = 1;
		else if (a[i][0] >= a[i][2] && a[i][2] >= a[i][1]) k[i][0] = 0, k[i][1] = 2;
		else if (a[i][1] >= a[i][0] && a[i][0] >= a[i][2]) k[i][0] = 1, k[i][1] = 0;
		else if (a[i][1] >= a[i][2] && a[i][2] >= a[i][0]) k[i][0] = 1, k[i][1] = 2;
		else if (a[i][2] >= a[i][0] && a[i][0] >= a[i][1]) k[i][0] = 2, k[i][1] = 0;
		else if (a[i][2] >= a[i][1] && a[i][1] >= a[i][0]) k[i][0] = 2, k[i][1] = 1;		
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (cnt[k[i][0]] + 1 <= n / 2)
		{
			cnt[k[i][0]] ++ ;
			q[k[i][0]].push(mk(a[i][k[i][0]], i));
		}
		else if (cnt[k[i][0]] == n / 2)
		{
			PII t = q[k[i][0]].top();
			q[k[i][0]].pop();
			if (t.x - a[t.y][k[t.y][1]] < a[i][k[i][0]] - a[i][k[i][1]])
			{
				q[k[i][0]].push(mk(a[i][k[i][0]], i));
				q[k[t.y][1]].push(mk(a[t.y][k[t.y][1]], i));
			}
			else
			{
				q[k[i][0]].push(t);
				q[k[i][1]].push(mk(a[i][k[i][1]], i));
			}
		}
	}
	for (int i = 0; i < 3; i ++ )
	{
		while (!q[i].empty())
		{
			res += q[i].top().x;
			q[i].pop();
		}
	}
	cout << res << endl;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T -- ) solve();
	return 0;
}


