#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int n, a[N];
long long ans;
void dfs(int id, int maxn, int sum){
	if(id > n){
		if(sum > maxn * 2){
			ans++;
			ans %= mod;
		}
		return;
	}
	dfs(id + 1, max(maxn, a[id]), sum + a[id]);
	dfs(id + 1, maxn, sum);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 1){
			flag = 0;
		}
	}
	if(n <= 20){
		dfs(1, 0, 0);
		cout << ans;
	}
	else if(flag == 1){
		for(int i = 3; i <= n; i++){
			int res = 1;
			for(int j = 1; j <= i; j++){
				res *= (n - j + 1);
			}
			for(int j = 1; j <= i; j++){
				res /= j;
			}
			ans += res;
			ans %= mod;
		}
		cout << ans;
	}
	return 0;
}
