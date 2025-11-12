#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, ans;
int a[N], b[N], c[N]; 
void dfs(int id, int cnt1, int cnt2, int cnt3, int res){
	if(id > n){
		ans = max(ans, res);
		return;
	}
	if(cnt1 + 1 <= n / 2){
		dfs(id + 1, cnt1 + 1, cnt2, cnt3, res + a[id]);
	}
	if(cnt2 + 1 <= n / 2){
		dfs(id + 1, cnt1, cnt2 + 1, cnt3, res + b[id]);
	}
	if(cnt3 + 1 <= n / 2){
		dfs(id + 1, cnt1, cnt2, cnt3 + 1, res + c[id]);
	}
	dfs(id + 1, cnt1, cnt2, cnt3, res); 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		}
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
} 
