#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ans = -1, cnt[4], ar[N][4], T, n;
void dfs(int k, int sum){
	if(k > n){
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(cnt[i] >= n / 2) continue;
		cnt[i]++;
		dfs(k + 1, sum + ar[k][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d", &ar[i][j]);
			}
		}
		dfs(1, 0);
		cout << ans << endl;
		ans = -1; 
	}
	return 0;
}
