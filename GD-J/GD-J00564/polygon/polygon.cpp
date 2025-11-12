#include <stdio.h>
int n, a[11451], cnt = 0;
void dfs(long long sum, long long mx_len, int id, int stick_cnt) {
	if(id == n + 1) {
		if(sum > mx_len * 2 && stick_cnt >= 3) {
			cnt += 1;
			cnt %= 998244353;
		}
		return ;
	}
	dfs(sum + a[id], (mx_len < a[id]) ? a[id] : mx_len, id + 1, stick_cnt + 1);
	dfs(sum, mx_len, id + 1, stick_cnt);
	return ;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int i;
	for(i = 1; i <= n; i += 1) scanf("%d", &a[i]);
	dfs(0, 0, 1, 0);
	printf("%d", cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
