#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
string s;
int c[105];
int p[105], p1[105];

int check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) p1[i] = p[i];
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1' && p1[c[i]] > 0) cnt++;
		else {
			for (int j = i; j <= n; j++) {
				p1[c[j]]--;
			}
		}
	}
	return cnt;
}

void dfs(int k) {
	if (k == n + 1) {
		if (check() >= m) ans++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		int fl = 1;
		for (int j = 1; j < k; j++) {
			if (c[j] == i) {
				fl = 0;
				break;
			}
		}
		if (fl) {
			c[k] = i;
			dfs(k + 1);
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	dfs(1);
	cout << ans << endl; 
	return 0;
} 
