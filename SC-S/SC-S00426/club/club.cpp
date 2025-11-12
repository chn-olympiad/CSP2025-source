#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, ans;
int a[N][4], b[N][4], cnt[N], num[N];
bool flag[N];
void DFS(int x, int m){
	if(x >= n){
		ans = max(ans, m);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(flag[i]) continue;
		for(int j = 1; j <= 3; j++){
			if(num[j] >= n / 2) continue;
			num[j]++;
			flag[i] = 1;
			DFS(x + 1, m + a[i][j]);
			flag[i] = 0;
			num[j]--;
		}
	}
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		ans = 0;
		bool sign = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(cnt, 0, sizeof(cnt));
		memset(num, 0, sizeof(num));
		memset(flag, 0, sizeof(flag));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			int x = 0, y = INT_MAX;
			for(int j = 1; j <= 3; j++){
				if(a[i][j] > x){
					x = a[i][j];
					b[i][1] = j;
				}		
			}
			for(int j = 1; j <= 3; j++){
				if(a[i][j] < y){
					y = a[i][j];
					b[i][3] = j;
				}		
			}
			for(int j = 1; j <= 3; j++)
				if(a[i][j] != x && a[i][j]!= y) b[i][2] = a[i][j];
		}
		for(int i = 1; i <= n; i++){
			ans += a[i][b[i][1]];
			cnt[b[i][1]]++;
		}
		for(int i = 1; i <= 3; i++){
			if(cnt[i] <= n / 2) continue;
			sign = 1;
			break;
		}
		if(sign != 0){
			ans = 0;
			DFS(0, 0);	
		}
		printf("%d\n", ans);
	}
	return 0;
} 