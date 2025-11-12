#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int mod = 998244353;

const int maxn = 510;

int n, m;

int s[maxn];
int c[maxn];

int lis[maxn];
int vis[maxn];

int res = 0;

bool check() {
	int cnt = 0;
	int cnt_ab = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt_ab >= c[lis[i]]) {
			cnt_ab++;
			continue;
		}
		if (s[i] == 1) {
			cnt++;
		} else {
			cnt_ab++;
		}
	}
	return cnt >= m;
}

void dfs(int p) {
	if (p == n + 1) {
		if (check()) res++;
		return;
	}
	
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		vis[i] = 1;
		lis[p] = i;
		dfs(p+1);
		vis[i] = 0;
		lis[p] = 0;
	}
}

void subtask1() {
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 0) ok = false;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) ok = false;
	}
	
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = (LL)res * i % mod;
	}
	if (ok) cout << res << endl;
	else cout << 0 << endl;
}

void solve() {
	cin >> n >> m;
	string str;
	cin >> str;
	str = ' ' + str;
	for (int i = 1; i <= n; i++) {
		s[i] = str[i] - '0';
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	if (m == n) {
		subtask1();
		return;
	}
	
	dfs(1);
	
	cout << res << endl;
}

void init() {
	
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	init();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
