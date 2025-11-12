#include <bits/stdc++.h>
using namespace std;

const int N = 5e3;
int a[N];
bool flag[N];
int cnt = 0;
int n;

void dfs(int maxn, int sum, int b, int j)
{
	if(sum > maxn * 2 && b >= 3)
	{
		cnt++;
	}
	for(int i = j; i <= n; i++)
	{
		int mm = maxn;
		if(flag[i] == 0)
		{
			sum += a[i];
			maxn = max(maxn, a[i]);
			b++;
			flag[i] = 1;
			dfs(maxn, sum, b, i);
			sum -= a[i];
			maxn = mm;
			b--;
			flag[i] = 0;
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	int maxnn = 0;
	int sunm = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxnn = max(maxnn, a[i]);
		sunm += a[i];
	}
	if(n == 3)
	{
		if(sunm > maxnn * 2)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else
	{
		dfs(0, 0, 0, 1);
		cout << cnt << endl;
	}
	return 0;
}
