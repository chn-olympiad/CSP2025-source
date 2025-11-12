#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[1565];
string s;
long long ans;
bool used[600];
void dfs(int depth, int out) {
	if(depth == n) {
		if(n - out >= m) ans = (ans + 1) % 998244353;
		return ;
	}
	for(int i = 1;i <= n;i ++) {
		if(!used[i]) {	
			used[i] = 1;
			if(c[i] <= out) {
				dfs(depth + 1, out + 1);
			}
			else {
				if(s[depth] == '0') {
					dfs(depth + 1, out + 1);
				}
				else {
					dfs(depth + 1, out);
				}
			}
			used[i] = 0;
		} 
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++) {
		cin >> c[i];
	}
	dfs(0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
