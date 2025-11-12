#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, a[5005], ans;
void dfs(int m, int maxx, int sum, int s){
	if(s >= 3){
		if(sum > maxx * 2){
			ans++;
			ans %= N;
		}
	}
	for(int i = m + 1; i <= n; i++){
		dfs(i, max(a[i], maxx), sum + a[i], s + 1);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++){
		dfs(i, a[i], a[i], 1);
	}
	printf("%d", ans);
	return 0;
}

