//GZ-S00354 程泊郡 安顺市第二高级中学
#include <bits/stdc++.h>
using namespace std;

const int N = 510, P = 998244353;
int a[N];
bool vis[N];
int n, m;
string s;
int c[N];
long long res;

bool check() {
	int ret = 0;
	int ret2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && ret < c[a[i]]) {
			ret2++;
			continue;
		}
		ret++;
	}
	if (ret2 == m) return true;
	return false;
}

void dfs(int s) {
	if (s == n) {
		if (check()) {
			res = (res + 1) % P;	
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			a[s] = i;
			vis[i] = 1;
			dfs(s + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}