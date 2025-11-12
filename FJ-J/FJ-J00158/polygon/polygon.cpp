#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010, mod = 998244353;

int n;
int res;
int len[N];

void dfs(int dep, int cnt, int sum, int mx)
{
	if (dep == n + 1)
	{
		res += (cnt >= 3 && sum > mx * 2);
		return;
	}
	
	dfs(dep + 1, cnt, sum, mx);
	dfs(dep + 1, cnt + 1, sum + len[dep], max(mx, len[dep]));
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i )
		scanf("%d", &len[i]);
	
	dfs(1, 0, 0, 0);
	
	printf("%d\n", res);
	return 0;
}
