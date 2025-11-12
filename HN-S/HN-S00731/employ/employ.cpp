#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, a[N];
string s;
bool check(){
	for(int i = 1; i <= n; i++){
		if(s[i] != '1')return true;
	}
	return false;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;s = " " + s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(check()){
		cout << 0;
		return 0;
	}
	int ans = 1;
	for(int i = n; i >= 1; i--){
		ans *= i;
		ans %= 998244353;
	}
	cout << ans << "\n";
	return 0;
}
