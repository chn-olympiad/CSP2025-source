#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 505, P = 998244353;
int n, m;
string s;
int a[N];

namespace baoli {
	int vis[N], p[N];
	int ans = 0;
	void dfs(int now, int pre) {
		if(now == n + 1) {
			if(n - pre >= m)
				ans++;
			return;
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i]) {
				p[now] = i; vis[i] = 1;
				if(pre >= a[i] || s[now] == '0') dfs(now + 1, pre + 1);
				else dfs(now + 1, pre);
				vis[i] = 0;
			}
	}
	void main() {
		dfs(1, 0);
		cout << ans << endl;
	}
}

int solve15() {
	for(int i = 1; i <= n; i++)
		if(s[i] == '0' || a[i] == 0) return 0;
	int ans = 1;
	for(int i = 1; i <= n; i++)
		ans = ans * i % P;
	return ans;
}

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s; s = " " + s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 18) {baoli::main(); return 0;}
	if(m == n) {cout << solve15() << endl; return 0;}
	cout << "I hate you, CCF" << endl;
	return 0;
}
/*
 * I hate you, CCF
 * AFO */
