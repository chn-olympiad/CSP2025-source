#include <bits/stdc++.h>
using namespace std;
int a[510];
int mp[510];
long long ret;
string s;
int n, m;
void dfs(int x, int re, int pa) {
	if(x == n) {
		if(pa >= m) {
			ret++;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if(!mp[i] && a[i] > re && s[x] == '1') {
			mp[i] = 1;
			dfs(x + 1, re, pa + 1);
			mp[i] = 0;
		}
		else if(!mp[i] && (a[i] <= re || s[x] == '0')) {
			mp[i] = 1;
			dfs(x + 1, re + 1, pa);
			mp[i] = 0;
		}
			
		
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int flag = 1;
	for (int i = 0; i < n; i++) if(s[i] != '1') flag = 0;
	if(flag == 1) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) ans = (ans * i) % 998244353;
		cout << ans << " ";
		return 0;
	}
	dfs(0, 0, 0);
	cout << ret;
	return 0;
}
//161088479
//35305197
//Ren5Jie4Di4Ling5%
