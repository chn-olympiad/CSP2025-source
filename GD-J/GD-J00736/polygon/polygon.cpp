#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 5005;
int n, a[N], choose[N], ans = 0;

void dfs(int cur) {
	if(cur > n) {
		int sum = 0, maxn = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(choose[i] == 1) {
				cnt++;
				sum += a[i];
				maxn = a[i];
			}
		}
		if(cnt >= 3) if(sum > 2 * maxn) ans++;
		return ;
	}
	choose[cur] = 0;
	dfs(cur + 1);
	choose[cur] = 1;
	dfs(cur + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n == 3) {
		if(a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
	} else {
		dfs(0);
		cout << ans / 2;
	}
	
	return 0;
}
