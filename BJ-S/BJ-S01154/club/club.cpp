#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
long long maxn = 0;

void dfs(int k)
{
	if (k == n + 1)
	{
		int cnta = 0, cntb = 0, cntc = 0;
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == 1)
			{
				cnta++;
				sum += a[i];
			}
			else if (d[i] == 2)
			{
				cntb++;
				sum += b[i];
			}
			else
			{
				cntc++;
				sum += c[i];
			}
		}
		if ((cnta > n / 2) || (cntb > n / 2) || (cntc > n / 2)) return;
		else maxn = max(maxn, sum);
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		d[k] = i;
		dfs(k + 1);
		d[k] = 0;
	}
	return;
}

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] != 0 || c[i] != 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			sort(a + 1, a + n + 1, cmp);
			int sum = 0;
			for (int i = 1; i <= n / 2; i++)
			{
				sum += a[i];
			}
			cout << sum << endl;
		}
		else
		{
			dfs(1);
			cout << maxn << endl;
			maxn = 0;
		}
	}
	return 0;
}