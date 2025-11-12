#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, maxall, maxnn = INT_MIN;
struct xs{
	int x1, x2, x3, fav1, fav2, fav3, favi1, favi2, favi3;
	int bad1 = 0, bad2 = 0, bad3 = 0;
}a[N];
void dfs(int sum, int x1, int x2, int x3, int x) {
	if(x > n) {
		maxnn = max(maxnn, sum);
		return ;
	}
	for(int i = x; i <= x; i ++) {
		if(a[i].favi1 == 1) {
			if(x1 < maxall)dfs(sum + a[i].fav1, x1 + 1, x2, x3, x + 1);
			
			if(a[i].favi2 == 2)dfs(sum + a[i].fav2, x1, x2 + 1, x3, x + 1);
			else dfs(sum + a[i].fav2, x1, x2, x3 + 1, x + 1);
		}else if(a[i].favi1 == 2) {
			if(x2 < maxall)dfs(sum + a[i].fav1, x1, x2 + 1, x3, x + 1);
			
			if(a[i].favi2 == 1)dfs(sum + a[i].fav2, x1 + 1, x2, x3, x + 1);
			else dfs(sum + a[i].fav2, x1, x2, x3 + 1, x + 1);
		}else{
			if(x3 < maxall)dfs(sum + a[i].fav1, x1, x2, x3 + 1, x + 1);
			
			if(a[i].favi2 == 2)dfs(sum + a[i].fav2, x1, x2 + 1, x3, x + 1);
			else dfs(sum + a[i].fav2, x1 + 1, x2, x3, x + 1);
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n);
		maxall = n / 2;
		for(int i = 1; i <= n; i ++) {
			scanf("%d%d%d", &a[i].x1, &a[i].x2, &a[i].x3);
			int maxn = max(a[i].x1, max(a[i].x2, a[i].x3));
			if(maxn == a[i].x1) {
				a[i].fav1 = a[i].x1;
				a[i].favi1 = 1;
				a[i].fav2 = max(a[i].x2, a[i].x3);
				a[i].favi2 = (a[i].x2 > a[i].x3 ? 2 : 3);
				a[i].fav3 = min(a[i].x2, a[i].x3);
				a[i].favi3 = (a[i].x2 > a[i].x3 ? 3 : 2);
			} else if(maxn == a[i].x2) {
				a[i].fav1 = a[i].x2;
				a[i].favi1 = 2;
				a[i].fav2 = max(a[i].x1, a[i].x3);
				a[i].favi2 = (a[i].x1 > a[i].x3 ? 1 : 3);
				a[i].fav3 = min(a[i].x1, a[i].x3);
				a[i].favi3 = (a[i].x1 > a[i].x3 ? 3 : 1);
			} else{
				a[i].fav1 = a[i].x3;
				a[i].favi1 = 3;
				a[i].fav2 = max(a[i].x2, a[i].x1);
				a[i].favi2 = (a[i].x2 > a[i].x1 ? 2 : 1);
				a[i].fav3 = min(a[i].x2, a[i].x1);
				a[i].favi3 = (a[i].x2 > a[i].x1 ? 1 : 2);
			}
		}
		dfs(0, 0, 0, 0, 1);
		printf("%d\n", maxnn);
		maxnn = INT_MIN;
	}
	return 0;
}
