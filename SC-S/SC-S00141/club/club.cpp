#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, t, a1[100010], a2[100010], a3[100010], mx;
void dfs(int c, int f, int s, int t, int g1, int g2, int g3){
	if(g1 > n / 2 || g2 > n / 2 || g3 > n / 2){
		return ;
	}
	if(c == n + 1){
		mx = max(mx, f + s + t);
		return ;
	}
	dfs(c + 1, f + a1[c], s, t, g1 + 1, g2, g3);
	dfs(c + 1, f, s + a2[c], t, g1, g2 + 1, g3);
	dfs(c + 1, f, s, t + a3[c], g1, g2, g3 + 1);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		mx = -1e9;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		dfs(1, 0, 0, 0, 0, 0, 0);
		cout << mx << "\n";
	}
	return 0;
} 