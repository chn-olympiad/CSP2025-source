#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 10;

int n, sum, a[N][3], pos[N], cnt[3];
vector<int> args[3];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	sum = 0;
	for(int j = 0; j <= 2; j ++) args[j].clear(), cnt[j] = 0;
	for(int i = 1; i <= n; i ++) {
		int t = -1, v = -1;
		for(int j = 0; j <= 2; j ++) 
			if(a[i][j] > v) t = j, v = a[i][j];
		cnt[t] ++; args[t].emplace_back(i); pos[i] = t;
		sum += v;
	}
	
	int u = -1;
	for(int j = 0; j <= 2; j ++) 
		if(cnt[j] > n/2) u = j;
		
	if(u == -1) {
		cout << sum << '\n';
		return ;
	}
	
	vector<int> err = {};
	int num = cnt[u] - n/2;
	for(int i : args[u]) {
		int v = -1;
		for(int j = 0; j <= 2; j ++) 
			if(j != pos[i] && a[i][j] > v) v = a[i][j];
		err.emplace_back(a[i][pos[i]] - v);
	}
	
	sort(err.begin(), err.end());
	for(int i = 0; i < num; i ++) sum -= err[i];
	cout << sum << '\n';
}

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
