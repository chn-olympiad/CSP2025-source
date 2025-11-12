#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int a[5000 + 5] = {};
int n;
int ans;
long long POW(long long a, long long b){
	long long res = 1;
	while (b){
		if (b & 1)res = (res * a) % MOD;
		a = (a * a) % MOD, b >>= 1;
	}
	return res;
}
void dfs(int i, int sum = 0, int maxn = 0){
	int nmaxn = max(maxn, a[i]);
	sum = sum + a[i];
	if (i > n) return;
	if(sum > nmaxn * 2){
		ans ++;
		
	} 
	dfs(i + 1, sum, nmaxn);
	dfs(i + 1, sum - a[i], maxn);
	return ;
}
void solve(){
	long long p[5005] = {1}, m[5005] = {1};
	for (int i = 1;i <= n;i++) {p[i] = (p[i - 1] * i) % MOD; m[i] = POW(p[i], MOD - 2);}
	long long ans2 = 0;
	for(int i = 3;i <= n;i++){
//		cout << m[(n - i)] << ' '  << m[(n - i)] * p[n-i]<< '\n';
		ans2 = (ans2 + ((p[n]*m[(n - i)]%MOD)*m[i]) % MOD) %MOD;
	}
//	cout << 1;
	cout << ans2;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    // program
    cin >> n;
    int maxn = 0, sum;
    for(int i = 1;i <= n;i++) {cin >> a[i];maxn = max(maxn, a[i]), sum += a[i];}
//    cout << -1;
    if(n == 3){
    	if(sum <= maxn * 2) cout << 0;
    	else cout << 1;
	}
	else if (n <= 20){dfs(1);
	cout << ans;}
	else if(maxn == 1){
//		cout << 1;
		solve();
	}
	cout << endl;
    return 0;
}
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
//1048365
