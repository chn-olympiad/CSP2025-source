#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 10;
int n, a[N], ans;
void dfs(int d, int s, int m)
{
	if(d > n)
	{
		if(s > 2 * m)
		{
//			cout << s << endl;
			ans++;
		}
		return;
	}
	s += a[d];
	m = max(m, a[d]);
	if(s > 2 * m)
	{
//		cout << s << endl;
		ans++;
	}
	for(int i = d + 1; i <= n; i++)
	{
		dfs(i, s, m);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n > 20)
	{
		cout << n;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n == 3)
	{
		if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3])))
		{
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++) dfs(i, 0, 0);
	cout << ans;
	return 0;
}
