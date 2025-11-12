#include<bits/stdc++.h>
using namespace std;
int n, m, c[101], res, v[101];
string s;
void dfs(int k, int r){
	if(k == n){
		if(r >= m){
			res ++;
			res %= 998244353;
		}
		return;
	}
	if(r + n - k < m) return;
	for(int i = 1; i <= n; i ++){
		if(v[i] == 0){
			v[i] = 1;
			if(c[i] > k - r && s[k] == '1'){
				dfs(k + 1, r + 1);
			}
			else{
				dfs(k + 1, r);
			}
			v[i] = 0;
		}
		
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
	}
	dfs(0, 0);
	cout << res % 998244353;
	return 0;
}
