#include<bits/stdc++.h>
using namespace std;
int n, a[1010][4];
int sum = 0;
void dfs(int i, int ar, int am, int br, int bm, int cr, int cm){
	if(i > n){
		if(ar > n / 2 || br > n / 2 || cr > n / 2){
			return ;
		}
		else{
			sum = max(sum, am + bm + cm);
		}
		return ;
	}
	dfs(i + 1, ar + 1, am + a[i][1], br, bm, cr, cm);
	dfs(i + 1, ar, am, br + 1, bm + a[i][2], cr, cm);
	dfs(i + 1, ar, am, br, bm, cr + 1, cm + a[i][3]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t > 0){
		sum = 0;
		t--;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		dfs(1, 0, 0, 0, 0, 0, 0);
		printf("%d\n", sum);
	}
} 
