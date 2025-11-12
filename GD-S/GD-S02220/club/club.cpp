#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5e5 + 5;
int t, n, ans, a[maxn][4];

void dfs(int x, int s, int d1, int d2, int d3){
	if(x == n + 1){
		ans = max(ans, s);
		return;
	}
	if(d1 + 1 <= n/2) dfs(x+1, s+a[x][1], d1+1, d2, d3);
	if(d2 + 1 <= n/2) dfs(x+1, s+a[x][2], d1, d2+1, d3);
	if(d3 + 1 <= n/2) dfs(x+1, s+a[x][3], d1, d2, d3+1);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
