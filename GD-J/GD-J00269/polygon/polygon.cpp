#include<bits/stdc++.h>
using namespace std;
int n, a[5001];
int ans;
void dfs(int p, int sum, int mx, int cnt){
	if(sum > 2 * mx && cnt >= 3)ans++;
	if(p > n){
		return ;
	}
	dfs(p + 1, sum + a[p], max(mx, a[p]), cnt + 1);
	dfs(p + 1, sum, mx, cnt);
} 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0);
	cout << (ans - n + 3) % 998244353;
	return 0;
}
