#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int cnt[5], ans;
int n;
void dfs(int k, int sum){
	if (cnt[1] > n / 2 || cnt[2] > n / 2 || cnt[3] > n / 2){
		return;
	}
	if (k == n + 1){
		if (sum > ans){
			ans = sum;
		}
		return;
	}
	for (int i = 1; i <= 3; i++){
		cnt[i]++;
		dfs(k + 1, sum + a[k][i]);
		cnt[i]--;
	} 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		dfs(1, 0);
		cout << ans << endl;
	}
	
	return 0;
} 







