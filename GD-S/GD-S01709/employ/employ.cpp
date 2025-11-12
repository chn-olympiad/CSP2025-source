#include<cstdio>
#define N 505
#define M 998244353
int ans = 0;
int n, m, b[N], q[N];
char a[N], u[N];
int qiu(){
	int i, r, c=0;
	for(i=1; i<=n; i++){
		r = q[i];
		if(a[i] == '0') c++;
		else if(c >= b[r]) c++;
	}
	return n-c;
}
void dfs(int k){
	if(k > n){
		int s = qiu();
		if(s >= m){
			ans = (ans+1)%M;
		}
		return;
	}
	int i;
	for(i=1; i<=n; i++){
		if(!u[i]){
			q[k] = i, u[i] = 1;
			dfs(k+1);
			u[i] = 0;
		}
	}
}
int main(){
	int i, j;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", a+1);
	for(i=1; i<=n; i++) scanf("%d", b+i);
	dfs(1);
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}//8
