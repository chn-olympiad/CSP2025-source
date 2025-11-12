#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
long long ans = 0;
clock_t st, ed;
void dfs(int now_id, long long choose, long long cnt){
	if(choose >= 3 && cnt > a[now_id-1] * 2){
		ans++;
		return ;
	}
	for(int i = now_id; i <= n; i++){
		dfs(i+1, choose+1, cnt + a[i]);
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	dfs(1, 0, 0);
	cout << ans % 998244353;
	return 0;
}

