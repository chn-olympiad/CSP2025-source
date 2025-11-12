#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct Node
{
	int a, b, c, d;
}t[100005];

bool cmp(Node x, Node y)
{
	return x.d > y.d;
}

int tmp = 0;

void dfs(int step, int ans, int cnta, int cntb, int cntc)
{
	if (step > n)
	{
		tmp = max(tmp, ans);
		return;
	}
	if (cnta < n / 2)
	{
		dfs(step + 1, ans + t[step].a, cnta + 1, cntb, cntc);
	}
	if (cntb < n / 2)
	{
		dfs(step + 1, ans + t[step].b, cnta, cntb + 1, cntc);
	}
	if (cntc < n / 2)
	{
		dfs(step + 1, ans + t[step].c, cnta, cntb, cntc + 1);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		bool flag = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> t[i].a >> t[i].b >> t[i].c;
			if (t[i].c > 0)
			{
				flag = 1;
			}
			t[i].d = t[i].a - t[i].b;
		}
		if (flag == 0)
		{
			int ans = 0;
			sort(t + 1, t + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
			{
				ans += t[i].a;
			}
			for (int i = n / 2 + 1; i <= n; i++)
			{
				ans += t[i].b;
			}
			cout << ans << endl;
		}
		else if (n <= 30)
		{
			tmp = 0;
			dfs(1, 0, 0, 0, 0);
			cout << tmp << endl;
		}
		else
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				ans += max(t[i].a, max(t[i].b, t[i].c));
			}
			cout << ans;
		}
	}
	return 0;
 } 
