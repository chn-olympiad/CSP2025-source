#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N]， ans = 0;
void dfs(int i, int mx, int sum, int cnt)
{
	
	if (i == n + 1)
	{
		if (sum > mx * 2 && cnt >= 3)
			ans++;
		return;
	}
	dfs(i + 1, mx, sum, cnt);
	dfs(i + 1, max(mx, a[i]), sum + a[i], cnt + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}