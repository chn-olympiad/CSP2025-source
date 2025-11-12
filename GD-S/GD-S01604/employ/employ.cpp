#include <cstdio>
const int N = 505, mo = 998244353;
int n, m, i, j, k, ans, s[N], t[N], f[N], p[N];
void dfs(int k){
	int i;
	if(k > n){
		int j, z = 0;
		for(j=1; i=p[j]; j++){
			if(z >= t[i]) z++;
			else if(s[j] == 0) z++;
		}
		ans += n-z>=m;
		return;
	}
	for(i=1; i<=n; i++){
		if(f[i]) continue;
		f[i] = 1, p[k] = i;
		dfs(k+1);
		f[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++) scanf("%1d", s+i);
	for(i=1; i<=n; i++) scanf("%d", t+i);
	if(n > m) dfs(1);
	else{
		for(k=0, i=1; i<=n; i++) k |= s[i]==0||t[i]==0;
		if(k) ans = 0;
		else{
			for(k=i=1; i<=n; i++) k = 1ll*k*i%mo;
			ans = k;
		}
	}
	printf("%d", ans);
	return 0;
}
