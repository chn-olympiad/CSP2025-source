#include<bits/stdc++.h>
using namespace std;
int n, a[5005], v[5005], ans;
void dfs(int c, int maxn, int k, int sh){
	if(maxn * 2 < c && k >= 3){
		ans ++;
		ans %= 998244353;
	}
	if(k == n) return;
	for(int i = sh; i <= n; i ++){
		if(!v[i]){
			v[i] = 1;
			dfs(c + a[i], max(maxn, a[i]), k + 1, i + 1);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	dfs(0, 0, 0, 1);
	cout << ans % 998244353;
	return 0;
}
