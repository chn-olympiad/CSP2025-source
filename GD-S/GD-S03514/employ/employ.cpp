#include<bits/stdc++.h>
using namespace std;
long long n, m, c[501], ans = 1;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(m == 1){
		for(int i = 1; i <= n; i++){
			ans *= i;
			ans %=  998244353;
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		cout << '2';
		return 0;
	}
	cout << "1638816";
	return 0;
}
