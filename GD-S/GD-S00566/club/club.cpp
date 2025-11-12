#include <bits/stdc++.h>
using namespace std;
int n, t, a[100005][5], num[5], sum, ans;
void dfs(int now){
	for (int i = 1; i <= 3; i++){
		if (num[i]+1 <= n/2){
			sum += a[now][i];
			++num[i];
			dfs(now+1);
			if (now == n){
				ans = max(ans, sum);
			}
			sum -= a[now][i];
			--num[i];
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		num[1] = num[2] = num[3] = 0;
		sum = 0;
		ans = 0;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}	
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
} 
