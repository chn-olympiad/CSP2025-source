#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
int arr[5005];
bool vis[5005];
void dfs(int maxl, int l, int maxm, int sum, int i){
	if (l >= maxl) {
		if (sum > maxm * 2){
			ans ++;
		}
		return;
	}
	for (i+1; i < n; i++){
		if (!vis[i]){
			vis[i] = true;
			dfs(maxl, l+1, max(maxm, arr[i]), sum + arr[i], i);
			vis[i] = false;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for (int i = 3; i <= n; i++){
		dfs(i, 0, 0, 0, 0);
	}
	ans = ans % 998244353;
	cout << ans;
	return 0;
}
