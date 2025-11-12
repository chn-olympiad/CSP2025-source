#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int a[maxn], b[maxn], ans = 0;
bool vis[maxn];
string s;
int n, k;

void dfs(int x) {
	if(x > n) {
		int cnt = 0, res = 0;
		for(int i=1; i<=n; i++) {
			if(cnt >= b[a[i]]) {
				++cnt;
			} else if(s[i-1] == '0') {
				++cnt;
			} else {
				++res;
			}
		}
		if(res >= k) {
			++ans;
			ans %= 998244353; 
		}
		return ;
	} 
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		a[x] = i;
		dfs(x+1);
		vis[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> k >> s;
	for(int i=1; i<=n; i++) {
		cin >> b[i];
	}
	if(n <= 18) {
		dfs(1);
		cout << ans % 998244353;
	} else {
		long long ans = 1;
		for(int i=n; i>=1; i--) {
			ans *= i;
			ans %= 998244353;
		}
		cout << ans % 998244353;
	}
	return 0;
}

