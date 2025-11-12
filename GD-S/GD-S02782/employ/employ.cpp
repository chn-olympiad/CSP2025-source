#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 505, mod = 998244353;

int n, m, ans, dif[N], c[N], ppl[N];
bool vis[N]; 

void dfs(int x, int tot, int cnt) {
	if(x == n + 1) {
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(!dif[x] || c[i] <= tot) dfs(x + 1, tot + 1, cnt);
		else dfs(x + 1, tot, cnt + 1);
		vis[i] = 0;
	}
}

int fac(int n) {
	int res = 1;
	for(int i = 1; i <= n; i++) res = res * i % mod;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		dif[i] = ch - '0';
		sum += dif[i];
		if(!dif[i]) flag = 0;
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 18) {
		dfs(1, 0, 0);
		cout << ans % mod << endl;
	}
	else if(flag) {
		cout << fac(n) << endl;
	}
	else if(m == n) cout << 0 << endl;
	else if(sum < m) cout << 0 << endl;
	return 0;
}
