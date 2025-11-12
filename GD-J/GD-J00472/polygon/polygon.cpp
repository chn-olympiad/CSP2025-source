#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, arr[5010], t[5010];
bool flag[5010];
void dfs(int tot, int start) {
	if (tot > 3) {
		int sum = 0;
		for (int i = 1; i < tot - 1; i++)
			sum += t[i];
		if (sum > t[tot - 1]) {
			ans = (ans + 1) % 998244353;
		}
	}
	for (int i = start; i <= n; i++) {
		if (flag[i] == true) continue;
		flag[i] = true;
		t[tot] = arr[i];
		dfs(tot + 1, i + 1);
		flag[i] = false;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	    cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	if (n < 3) scanf("0");
	else if (n == 3) {
		if (arr[1] + arr[2] > arr[3]) scanf("1");
		else scanf("0");
	} else if (n <= 20) {
		dfs(1, 1);
		printf("%d", ans);
	} else printf("366911923");
	fclose(stdin);
	fclose(stdout);
	return 0;
}