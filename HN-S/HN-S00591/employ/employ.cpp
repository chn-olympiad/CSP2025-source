#include <bits/stdc++.h>
#define int long long
using namespace std;

string yq;
int peop[100100], pl[100100], ans = 0, vis[100100];
int n, m;

bool check() {
	int tt = 0, ly = 0;
	
	
	for(int i = 1; i <= n; i ++) {
		if(yq[i - 1] == '0') {
			tt ++;
			continue;
		}
		if(pl[i] <= tt) {
			tt ++;
			continue;
		}
		ly ++;
	}

	return ly >= m;
}

void dfs(int now) {
	if(now == n + 1) {
		if(check()) {
			ans ++;
			ans %= 998244353; 
		}
		return ;
	}
	
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) {
			vis[i] = 1;
			pl[now] = peop[i];
			dfs(now + 1);
			pl[now] = 0;
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	
	cin >> yq;
	
	bool flg = 0;
	for(int i = 0; i < yq.size(); i ++) {
		if(yq[i] == '0') {
			flg = 1;
		}
	}
	
	
	for(int i = 1; i <= n; i ++) {
		cin >> peop[i];
	}
	
	if(flg == 0) {
		long long ans = 1;
		for(int i = 1; i <= n; i ++) {
			ans *= i;
			ans %= 998244353;
		}
		cout << ans << endl;
		return 0; 
	}
	
	dfs(1);
	//cout << (int)check() << endl;
	
	cout << ans << endl;
}
