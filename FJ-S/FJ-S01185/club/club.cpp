#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int t, n, ans = 0; 
int a[N], b[N], c[N], e[4]; 

void dfs(int x, int s, int cnt) {
	if (e[x] > n / 2) return;
	if (s == n) {
		ans = max(cnt, ans);
		return;
	}
	e[1]++, dfs(1, s + 1, cnt + a[s + 1]), e[1]--;
	e[2]++, dfs(2, s + 1, cnt + b[s + 1]), e[2]--;
	e[3]++, dfs(3, s + 1, cnt + c[s + 1]), e[3]--;
	return;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		e[1]++, dfs(1, 1, a[1]), e[1]--;
		e[2]++, dfs(2, 1, b[1]), e[2]--;
		e[3]++, dfs(3, 1, c[1]), e[3]--;
		cout << ans << '\n';
	}
	
	return 0;
}
/*
退役倒计时 
你知道我打了这题打了大半场，一百多行，发现自己的思路被样例 hack 了的时候有多绝望吗
爆搜是最后十分钟写的。 
我觉得今年这场甚至比去年 noip 还难，那次我至少还能打点部分分，这次我很多特殊性质都不知道怎么做 
我顶多只会普及算法，dp 都写不清楚。
去年拿了二等 今年怎么就都不会写了 怎么会掉这么多  
高二了专心学文化课罢
*/
