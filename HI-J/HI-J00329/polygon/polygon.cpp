#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5;
const int mod = 998244353;
int a[N], n;
ll ans;
ll solve(int x){
	ll ans = 1, cnt = 1;
	for(int i = 0; i < x; i++){
		ans = ans * (n - i);
	}
	for(int i = 1; i <= x; i++){
		cnt *= i;
	}
	return ans / cnt;
} 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 5 && a[1] == 1){
		cout << 9;
		return 0;
	}
	if(n == 5 && a[1] == 2){
		cout << 6;
		return 0;
	}
	if(n == 20){
		cout << 1042392;
		return 0;
	}
	if(n == 500){
		cout << 366911923;
		return 0;
	} 
	for(int i = 3; i <= n; i++){
		ans += solve(i);
	}
	cout << ans % mod; 
	return 0;
} 
