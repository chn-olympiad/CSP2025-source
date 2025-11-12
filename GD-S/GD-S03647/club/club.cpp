#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5+10;
int n, k, ans, a[mxn][3], c[3], b[3][mxn];
void solve(){
	ans = 0; c[0] = c[1] = c[2] = 0;
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
			ans += a[i][0];
			b[0][++c[0]] = a[i][0] - max(a[i][1], a[i][2]);
		}else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
			ans += a[i][1];
			b[1][++c[1]] = a[i][1] - max(a[i][2], a[i][0]);
		}else{
			ans += a[i][2];
			b[2][++c[2]] = a[i][2] - max(a[i][0], a[i][1]);
		}
	}
//	printf("c %d %d %d\n", c[0], c[1], c[2]);
	if(c[0] > n >> 1){
		sort(b[0] + 1, b[0] + c[0] + 1);
		k = c[0] - (n >> 1);
		for(i = 1; i <= k; i++){
			ans -= b[0][i];
		}
	}else if(c[1] > n >> 1){
		sort(b[1] + 1, b[1] + c[1] + 1);
		k = c[1] - (n >> 1);
		for(i = 1; i <= k; i++){
			ans -= b[1][i];
		}
	}else if(c[2] > n >> 1){
		sort(b[2] + 1, b[2] + c[2] + 1);
		k = c[2] - (n >> 1);
		for(i = 1; i <= k; i++){
			ans -= b[2][i];
		}
	}
	printf("%d\n", ans);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}
