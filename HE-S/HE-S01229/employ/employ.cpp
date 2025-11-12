#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 1;
int a[505];
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1 && s[0] == '0'){
		for(int i = 1; i <= n; i++){
			ans *= i;
		}
		cout << ans % 998244353;
	}
	return 0;
}
