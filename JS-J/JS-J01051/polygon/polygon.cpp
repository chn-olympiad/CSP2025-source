#include<bits/stdc++.h>
using namespace std;
int a[5001], vis[5001];
int ans;
int n;
void DFS(int m, int step, int num, int last)
{
	if (step == m)
	{
		if (num > a[last] * 2) 
		{
			ans++;
		}
		return;
	}
	for (int i = last + 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			DFS(m, step + 1, num + a[i], i);
			vis[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
		sort(a + 1, a + n + 1);
		for (int i = 3; i <= n; i++)
		{
			DFS(i, 0, 0, 0);
		}
		cout << ans;
	
	return 0;
}
