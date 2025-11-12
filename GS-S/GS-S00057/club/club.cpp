#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
int n, op, ans, a[N][5];

void Dfs(int step, int x, int a1, int a2, int a3)
{
	if(a1 > (n / 2) || a2 > (n / 2) || a3 > (n / 2)) return;
	if(step > n)
	{
		ans = max(x, ans);
		return;
	}
	Dfs(step + 1, x + a[step][1], a1 + 1, a2, a3);
	Dfs(step + 1, x + a[step][2], a1, a2 + 1, a3);
	Dfs(step + 1, x + a[step][3], a1, a2, a3 + 1);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> op;
	for (int i = 1; i <= op; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		Dfs(0, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
