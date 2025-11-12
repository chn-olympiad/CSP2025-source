#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[505];
int ans[15][3];
int vis[15];
const int mod = 998244353;
int daan = 0;
void dfs(int num){
	if(num == n + 1){
		int notgo = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0'){
				notgo++;
			}
			else if(notgo >= ans[i][2]){
				notgo++;
			}
		}
		if(n - notgo >= m){
			daan++;
			daan %= mod;
		}
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] != 1){
			vis[i] = 1;
			ans[num][1] = i;
			ans[num][2] = c[i];
			dfs(num + 1);
			vis[i] = 0;
			ans[num][1] = 0;
			ans[num][2] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(n <= 10){
		dfs(1);
		cout << daan << endl;
	}
	else{
		cout << 0 << endl;
	}
}
