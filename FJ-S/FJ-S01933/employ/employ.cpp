#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const long long mod = 998244353;
char cc[N];
bool s[N];
int n,m,c[N];
long long fct[N] = {1},ans = 1;
bool vis[N];
int re[N];
long long dfs(int x){
	if(x > n){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(i - cnt - 1 < c[re[i]] && s[i]) ++cnt;
		}
		return cnt >= m;
	}
	long long res = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = true,re[x] = i;
		res += dfs(x + 1);
		vis[i] = false;
	}
	return res;
}
int d[N],top,cnt,ttop = n,f[1 << 20];
bool acc[N];
long long sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",cc);
	for(int i = 0; i < n; i++) s[i + 1] = (cc[i] == '1');
	for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
	sort(c + 1,c + n + 1);
	for(int i = 1; i <= 500; i++) fct[i] = fct[i - 1] * i % mod;
	if(m == n){
		for(int i = 1; i <= n; i++){
			if(!s[i]){
				printf("0\n");
				return 0;
			}
		}
		if(c[1] == 0) printf("0\n");
		else printf("%lld\n",fct[n]);
	}else if(m == 1){
		for(int i = n; i >= 1; i--) ans = ans * (i - c[i]) % mod;
		printf("%lld\n",(fct[n] + mod - ans) % mod);
	}else{
		printf("%lld\n",dfs(1) % mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
