//T4 polygon
#include <bits/stdc++.h>
using namespace std;
long long n, a[1234567], cnt, b[1234567], ans;
void dfs(int num, int cnt, int sum1, int sum2, int pre) {
	if(cnt > num) {
		ans += (sum1 < sum2);
		return;
	}
	if(cnt == 1)pre++;
	for(int j = num - cnt + 1; j < pre; j++) {
		if(cnt == 1) dfs(num, cnt + 1, a[j], sum2, j);
		else dfs(num, cnt + 1, sum1, sum2 + a[j], j);
	}
}
long long px(int q) {
	if(q <= 1)return 1;
	else return q * px(q - 1);
}
long long kkk(int x, int y) {
	return px(x) / (px(y) * px(x - y));
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)b[i] = b[i - 1] + a[i];
	for(int i = 3; i <= n; i++) dfs(i, 1, 0, 0, n);
	cout << ans;
	return 0;
}
//我要吃麦当劳！
