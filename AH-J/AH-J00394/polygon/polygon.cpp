#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
int n, num = 0;
int a[N];

void dfs(int idx, int cnt, int ans, int end) {
	if (idx > n) {
		if (cnt >= 3 && ans > end*2) {
			num++;
			num %= 998244353;
		}
		return;
	}
	dfs(idx+1, cnt+1, ans+a[idx], a[idx]);
	dfs(idx+1, cnt, ans, end);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	dfs(1, 0, 0, 0);
	printf("%d\n", num);
	return 0;
}
