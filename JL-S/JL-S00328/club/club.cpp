#include <bits/stdc++.h>
using namespace std;
int n, a[4][100005], b, sum, ans[4], id[4][100005], a1[100005], f1[100005], t;
bool cmp(int a, int b)
{
	return a > b;
}
int f(int i, int sum1, int sum2, int sum3)
{
	if(i == n)
	{
		int t = 0;
		if(sum1 < n / 2)
		{
			t = max(t, a[1][i]);
		}
		if(sum2 < n / 2)
		{
			t = max(t,  a[2][i]);
		}
		if(sum3 < n / 2)
		{
			t = max(t, a[3][i]);
		}
		return t;
	}
	if(f1[i] != 0)
	{
		return f1[i];
	}
	if(sum1 < n / 2)
	{
		f1[i] = max(f(i + 1, sum1 + 1, sum2, sum3) + a[1][i], f1[i]);
	}
	if(sum2 < n / 2)
	{
		f1[i] = max(f(i + 1, sum1, sum2 + 1, sum3) + a[2][i], f1[i]);
	}
	if(sum3 < n / 2)
	{
		f1[i] = max(f(i + 1, sum1, sum2, sum3 + 1) + a[3][i], f1[i]);
	}
	return f1[i];
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		memset(a1, 0, sizeof(a1));
		memset(ans, 0, sizeof(ans));
		memset(f1, 0, sizeof(f1));
		b = 2;
		sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[2][i] != 0)
			{
				b = 0;
			}
			else if(a[3][i] != 0 && b != 0)
			{
				b = 1;
			}
			else if(a[2][i] == a[3][i] && a[3][i] == 0 && b == 2)
			{
				b = 2;
			}
		}
		if(b == 2)
		{
			for(int i = 1; i <= n; i++)
			{
				a1[i] = a[1][i];
			}
			sort(a1, a1 + n, cmp);
			for(int i = 1; i <= n / 2; i++)
			{
				sum += a1[i];
			}
			cout << sum << '\n';
		}
		else
		{
			cout << f(1, 0, 0, 0) << '\n';
		}
	}
	return 0;
}
