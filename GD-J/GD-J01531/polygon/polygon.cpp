#include <bits/stdc++.h>
using namespace std;
int  n;
const int mod = 998244353;
int a[5005], ans;
void dfs(int sum, int m, int mi){
	if (sum > 2 * m){
		ans = (ans + 1) % mod;
	}
	for (int i = mi + 1; i <= n; i++){
		dfs(sum + a[i], a[i], i);
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	sort(a + 1, a + n + 1);
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
} 

