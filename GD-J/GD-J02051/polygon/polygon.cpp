#include <stdio.h>
#include <bits/stdc++.h>
#define min(a,b) a<b?a:b
using namespace std;
int ans, m, n, i, j, k, a[5005];
long long b[1005];
void dfs(int s, int k, int w){
	if(k<1){
		if(w>s) ans++;
		return;
	}
	if(b[k]<=s-w) return;
	dfs(s, k-1, w+a[k]);
	dfs(s, k-1, w);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	for(i=1; i<=n; i++) b[i]=b[i-1]+a[i];
	for(i=3; i<=n; i++){
		dfs(2*a[i], i, 0);
		ans%=998244353;
	}
	printf("%d", ans);
	return 0;
}
