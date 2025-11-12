#include<bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 7;
int n, a[kN][5], p[10], f[kN], ans;
int dfs(int cur, int sum){
	if(f[cur] != -1){
		return f[cur] = max(f[cur], sum);
	}
	if(cur > n){
		return f[cur] = max(sum, f[cur]);
	}
	int num = 0;
	for(int i = 1; i <= 3; ++i){
		if(p[i] < n / 2){
			p[i]++;
			num = max(dfs(cur + 1, sum + a[cur][i]), num);
			p[i]--;
		}
	}
	return max(f[cur], num);
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 3; ++j){
			cin >> a[i][j];
			p[j] = 0;
		}
	}
	fill(f + 1, f + 5 + n, -1);
	cout << dfs(1, 0) << "\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
