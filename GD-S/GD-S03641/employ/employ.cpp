#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
int n, m, c[N], ans[N], stu[N];
string s;	
long long cnt;
void dfs(int u) {
	if (u == n+1) {
		int nc = 0, sum = 0;
		for (int i = 1; i < u; i++) {
			if (s[i-1] == '0' || c[ans[i]] <= nc) {
				nc++;
			} else {
				sum++;
			}
		}
		if (sum >= m) {
			cnt++;
			cnt %= mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!stu[i]) {
			stu[i] = 1;
			ans[u] = i;
			dfs(u+1);
			stu[i] = 0;
		} 
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1);
	cout << cnt % mod;
	return 0;
}
