#include <bits/stdc++.h>
using namespace std;
int n, m, ans, s[505], c[505], p[505], f[505];
void dfs(int step){
	if(step > n){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(i - 1 - cnt >= c[p[i]]) continue;
			if(s[i] == 1) cnt++;
		} 
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(f[i]) continue;
		f[i] = 1;
		p[step] = i;
		dfs(step + 1);
		f[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> ch;
		s[i] = ch - '0';
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}
