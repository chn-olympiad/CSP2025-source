#include<bits/stdc++.h>
using namespace std;
int n, maxa, ah, ans, a[5010], na[5010];
bool vis[5010];
void dfs(int i1, int xh);
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	dfs(1, 1);
	ans %= 998 * 244 * 353;
	printf("%d", ans);
	return 0;
}
void dfs(int i1, int xh){
	for(int i = i1; i <= n; ++i) {
		if(!vis[i]) {
			ah += a[i];
			vis[i] = 1;
			na[xh] = a[i];
			maxa = max(maxa, a[i]);
			if(xh >= 3 && ah > maxa * 2) {
				ans %= 998 * 244 * 353;
				++ans;
			}
			dfs (i + 1, xh + 1);
			if(maxa == a[i]) {
				maxa = 0;
				for(int j = 1;j <= xh - 1; ++j){
					maxa = max(maxa, a[j]);
				}
			}
			ah -= a[i];
			vis[i] = 0;
			na[xh] = 0;
		}
	}
	return;
}
//#Shang4Shan3Ruo6Shui4
