#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 35;
int t, n, ans = 0, a[maxn][5], sum = 0;

void dfs(int cur, int b1, int b2, int b3){
	if(b1 > n/2 || b2 > n/2 || b3 > n/2) return;
	if(cur > n) ans = max(ans, sum);
	for(int i = 1; i <= 3; i++){
		sum += a[cur][i];
		if(i == 1){
			dfs(cur + 1, b1+1, b2, b3);
		}else if(i == 2){
			dfs(cur + 1, b1, b2+1, b3);
		}else{
			dfs(cur + 1, b1, b2, b3+1);
		}
		sum -= a[cur][i];
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0, sum = 0;
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs(1, 0, 0, 0);
		cout << ans << endl;
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
/*Ren5Jie4Di4Ling5%*/
