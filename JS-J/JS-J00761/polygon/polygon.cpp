#include <bits/stdc++.h>
using namespace std;
int n, a[5000];
long long sum;
void dfs(int t, long long s, int mx)
{
	if(t > n)
	{
		if(s > 2 * mx)
		{
			sum++;
		}
		return;
	}
	dfs(t + 1, s, mx);
	dfs(t + 1, s + a[t], max(mx, a[t]));
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int am = 0;
    for (int i = 1; i <= n; i++)
    {
		cin >> a[i];
		am = max(am, a[i]);
	}
	if(n == 3)
	{
		if(a[1] + a[2] + a[3] - am > am)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
		return 0;
	}
	if(am == 1)
	{
		int x = n;
		x *= (n - 1);
		x /= 2;
		for (int i = n - 2; i >= 1; i--)
		{
			x *= i;
			x /= (n - i + 1);
			sum += x;
		}
		cout << sum << '\n';
		return 0;
	} 
	dfs(1, 0, 0);
	cout << sum << '\n';
	return 0;
}
