#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int Max_n = 510;
int n, m;
string s;
int c[Max_n], vis[Max_n], ans;
void dfs(int x, int sum, int cnt){
	if(cnt == m){
		long long cnn = 1;
		for(int i = 1; i <= n - x; i++){
			cnn = 1ll * cnn * i % Mod;
		}
		ans =(ans + cnn) % Mod;
		//cout << cnn << endl;
		return ;
	}
	if(x == n)return ;
	for(int i = 1; i <= n; i++){
		if(vis[i])continue ;
		if(sum >= c[i] || s[x] == '0'){
			vis[i] = 1;
			dfs(x + 1, sum+1, cnt);
			vis[i] = 0;
		}else{
			vis[i] = 1;
			dfs(x + 1, sum, cnt+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}