#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[505];
long long ans;
bool vis[505];
long long f(int x) {
	long long ans = 1;
	for(int i = 1; i <= x; i++) {
		ans  = ans * i % 998244353;
	}
	return ans;
	
}
void dfs(int x, int cnt) {
//	cout << x << ' ' << cnt << endl;
	if(x == n + 1) {
		if(cnt >= m)ans = (ans + 1) % 998244353;
		return ;
	}
	if(n - x + 1 < m - cnt) return ;
	for(int i = 1; i <= n; i++) {
//		if(x == 1) cout << i << endl;
		if(vis[i]) continue;
		vis[i] = 1;
		if(x - cnt - 1 >= a[i]) {
			dfs(x + 1, cnt);
		}else {
			if(s[x - 1] == '0') {
				dfs(x + 1, cnt);
			}else {
				dfs(x + 1, cnt + 1);
			}
		}
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	} 
	dfs(1, 0);
	printf("%lld", ans);
	return 0;
} 
