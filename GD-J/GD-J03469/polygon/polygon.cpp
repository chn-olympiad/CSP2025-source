#include<bits/stdc++.h> 
using namespace std;
const int N = 998244353;
int a[5010];
int n;
long long ans;
long long f(int x, int y) {
	long long cnt = 1, cntt = 1;
	for(int i = 0; i < y; i++) {
		cnt = cnt * (x - i);
		cntt = cntt * (y - i);
		cnt = cnt % N;
		cntt = cntt % N;
	}
	return cnt / cntt;
}
void dfs(int u, int maxx, int sum, int num) {
	if(num >= 3 && maxx * 2 < sum) {
		ans++;
		ans %= N;
		if(u == n + 1) {
			return;
		}
		dfs(u + 1, max(maxx, a[u]), sum + a[u], num + 1);
		return;
	}
	if(u == n + 1) {
		return;
	}
	dfs(u + 1, maxx, sum, num);
	dfs(u + 1, max(maxx, a[u]), sum + a[u], num + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[n] == 1) {
		for(int i = 3; i <= n; i++) {
			ans += f(n, i);
			ans = ans % N;
		}
		cout << ans;
	} else if(n <= 20) {
		for(int i = 1; i <= n - 2; i++) dfs(i + 1, a[i], a[i], 1);
		cout << ans % N;
	} else {
		cout << N;
	}
	return 0;
}
