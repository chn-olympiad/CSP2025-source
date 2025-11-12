#include<cstdio>
#define N 5005
#define M 998244353
int n, a[N], ans;
void dfs(int k, int c, int s, int maxn){
	if(k > n){
		if(c>2 && s>(maxn<<1)) ans = (ans+1)%M;
		return;
	}
	dfs(k+1, c+1, s+a[k], maxn>a[k]?maxn:a[k]);
	dfs(k+1, c, s, maxn);
}
int main(){
	int i, j;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n;i++) scanf("%d", a+i);
	dfs(1, 0, 0, 0);
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}//Ô¤¹À40 
