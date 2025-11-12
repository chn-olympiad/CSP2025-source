#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long ans = 0;
int n;
void dfs(int cur, int maxn, long long sum, int cnt){
	if(cur == n + 1){
		if(cnt <= 2) return ;
		ans += (sum > maxn * 2);
		ans %= 998244353;
		return ;
	}
	dfs(cur + 1, max(maxn, a[cur]), sum + a[cur], cnt + 1);
	dfs(cur + 1, maxn, sum, cnt);
}
set<priority_queue<int>> se;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0); 
	cout << ans << endl;
	return 0; 
} 
