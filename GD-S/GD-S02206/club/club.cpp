#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T, n, t, tt, ttt;
int a[maxn][4];
int ans;
//LumineScence Forever!!
void search(int x, int t, int tt, int ttt, int num){
	if(x == n + 1){
		ans = max(ans, num);
		return ;
	}
	if(t + 1 <= n / 2) search(x + 1, t + 1, tt, ttt, num + a[x][1]);
	if(tt + 1 <= n / 2) search(x + 1, t, tt + 1, ttt, num + a[x][2]);
	if(ttt + 1 <= n / 2) search(x + 1, t, tt, ttt + 1, num + a[x][3]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		ans = 0;
		search(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
