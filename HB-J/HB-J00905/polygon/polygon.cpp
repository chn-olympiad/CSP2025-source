#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int n, ans = 0;
int a[5001];

void dfs(int sum, int j, int v, bool b, int i){
	if (i > n + 1)
		return;
	if (j >= 3 && sum > v * 2 && b)
		ans = (int)((ans + 1LL) % P);
	dfs(sum + a[i], j + 1, a[i], true, i + 1);
	dfs(sum, j, v, false, i + 1);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(0, 0, 0, false, 1);
	printf("%d", ans);
	return 0;
}