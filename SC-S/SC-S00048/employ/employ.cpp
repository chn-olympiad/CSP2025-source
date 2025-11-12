#include <bits/stdc++.h>

using namespace std; 

int n, m, cnt;
char S[505]; 
int C[505];
bool vis[505];

void Dfs (int cur, int fl, int ac) {
	if (cur == n + 1) {
		if (ac >= m) 
			cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			Dfs(cur + 1, fl + (S[cur] == '0' || fl > C[i]), ac + (S[cur] == '1' && fl <= C[i]));
			vis[i] = 0;
		}
	}
}

int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout); 
    
	cin >> n >> m;
	cin >> (S + 1);
	if (m == n) {
		for (int i = 1; i <= n; i++) 
			if (S[i] == '0') {
				cout << "0";
				return 0;
			}
			long long res = 1;
			for (int i = 2; i <= n; i++) 
				(res *= i) %= 998244353;
			cout << res;
			return 0;
	} else {
		bool flag = 1;
		for (int i = 1; i <= n; i++) 
			if (S[i] == '0') {
				flag = 0;
				break;
			}
		if (flag) {
			long long res = 1;
			for (int i = 2; i <= n; i++) 
				(res *= i) %= 998244353;
			cout << res;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) 
		cin >> C[i];
	Dfs(1, 0, 0);
	cout << cnt;
	return 0;
}