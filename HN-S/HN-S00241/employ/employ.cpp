#include<bits/stdc++.h>

using namespace std;


const int MAXN = 5e2 + 52, MOD = 998244353;

int n, m;
string s;
int c[MAXN];
bool use[MAXN];

int dfs(int i, int cnt) {
	if(n - i + 1 + cnt < m)return 0;
	if(i == n + 1)return cnt >= m;
	int ans = 0;
	for(int j = 1; j <= n; j++) {
		if(use[j])continue;
		bool k = (s[i - 1] == '1') && i - cnt - 1 < c[j];
		use[j] = 1;
		ans += dfs(i + 1, cnt + k);
		use[j] = 0;
		ans %= MOD;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << dfs(1, 0);
	return 0;
}
