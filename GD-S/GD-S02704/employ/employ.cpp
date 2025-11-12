#include <bits/stdc++.h>

using namespace std;

const int N = 555, MOD = 998244353;
deque<int> q;
bool s[N], use[N];
int p[N], n, m, ans;
int C(int a, int b) {
	int ans = 1;
	for(int i = n; i >= n - b + 1; i--) {
		ans *= i;
		ans %= MOD;
	}
	for(int i = 2; i <= b; i++) {
		ans /= i;
	}
	return ans;
}
void A() {
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans;
} 
void MO() {
	
}
void dfs(int nn) {
	if(nn == n) {
		int nl = 0;
		int po = 0, cnt = 0;
		deque<int> qq = q;
		while(!qq.empty()) {
			po++;
			int qp = qq.front();
			qq.pop_front();
			if(nl >= qp) {
				nl++;
				continue;
			}
			if(s[po]) {
				cnt++;
			}
			else {
				nl++;
			}
		}
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!use[i]) {
			use[i] = true;
			q.push_back(p[i]);
			dfs(nn + 1);
			q.pop_back();
			use[i] = false;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool cA = true;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
		if(s[i] == 0) {
			cA = false;
			cnt++;
		}
	}
	for(int i = 1; i <= n; i++) cin >> p[i];
	if(cA) {
		A();
		return 0;
	}
	if(m == 1) {
		MO();
	}
	dfs(0);
	cout << ans;
	
	return 0;
} 
