#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int n, m, ans, c[505];
string s;
bool f[505];
void dfs(int step, int num, int cnt){
	if(step > n){
		if(cnt >= m) ans++;
		if(ans >= MOD) ans = 0;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(f[i]) continue;
		f[i] = 1;
		if(c[i] <= num || s[step] == '0') dfs(step + 1, num + 1, cnt);
		else{
			dfs(step + 1, num, cnt + 1);
		}
		f[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	bool fl2 = 1;
	for(int i = 1; i <= n; i++){
		if(c[i]){
			fl2 = 0;
			break;
		}
	}
	if(fl2){
		cout << (m < 1 || (m == 1 && s[1] == '1'));
		return 0;
	}
	if(m == n){
		for(int i = 1; i <= n; i++){
			if(s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		ll mul = 1;
		for(int i = 1; i <= n; i++) mul = mul * i % MOD;
		cout << mul;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
