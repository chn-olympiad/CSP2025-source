#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, c[505], ans = 1, num;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	num = n;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		if (c[i] == 0){
			num--;
		}
	}
	for (int i = num; i >= 1; i--){
		ans = (ans * i) % MOD;
	}
	cout << ans % MOD;
	return 0; 
} 
