#include<cstdio>
#include<cstring>
#define N 500005
int n, m, a[N], ans;
int f[N][270];
void dfs(int k, int s, char xuan, int c){
	if(k > n){
		if(s==m && c>ans) ans = c;
		return;
	}
	if(c <= f[k][s]) return;
	f[k][s] = c;
	if(!xuan){
		dfs(k+1, 0, 0, c);
		dfs(k+1, a[k], 1, c+1);
	}
	if(s == m){
		dfs(k+1, 0, 0, c);
		dfs(k+1, a[k], 1, c+1);
	}else dfs(k+1, s^a[k], 1, c);
}
int main(){
	int i, j;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++) scanf("%d", a+i);
	memset(f, -1, sizeof(f));
	dfs(1, 0, 0, 0);
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}//Ô¤¹À20 
