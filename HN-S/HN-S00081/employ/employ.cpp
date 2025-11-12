#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, ans;
int add(int n){
	if (n == 1)
		return 1;
	return add(n - 1) + n;
}
void cnt(int n, int m){
	if (n == 1){
		ans = (ans + 1) % mod;
		return ;
	}
	if (m == 2){
		ans = (ans + add(n)) % mod;
		return ;
	}
	for (int i = 1; i <= n; i++)
		cnt(i, m - 1);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cnt(n - m + 1, m);
	cout << ans;
	fclose(stdin); fclose(stdout);
	return 0;
} 
