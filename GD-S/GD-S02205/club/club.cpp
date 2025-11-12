#include<bits/stdc++.h>
using namespace std;

int t, n, ans;
int a[100005][5];
void dfs(int cur, int sum, int gs1, int gs2, int gs3){
	if(max(max(gs2, gs3), gs1) > n / 2) return;
	if(cur == n + 1){
		ans = max(ans, sum);
		return;
	}
	dfs(cur + 1, sum + a[cur][1], gs1 + 1, gs2, gs3);
	dfs(cur + 1, sum + a[cur][2], gs1, gs2 + 1, gs3);
	dfs(cur + 1, sum + a[cur][3], gs1, gs2, gs3 + 1);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
} 
