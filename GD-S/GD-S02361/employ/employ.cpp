#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n, m, a[510], b[510], v[510], flag, fleg, flg, z, mina = 2e9;
char c[510];
long long ans;
void p(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] == '0' || cnt >= a[v[i]]) cnt++;
//		cout << a[v[i]] << ' ';
	} 
//	cout << endl;
	if(n - cnt >= m) ans++;
//	cout << ans << endl;
}
void dfs(int x){
	for(int i = 1; i <= n; i++){
		if(!b[i]){
			b[i] = 1;
			v[x] = i;
			if(x == n) p();
			else dfs(x + 1);
			b[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i]) flag = 1, mina = min(mina, a[i]);
		else z++;
		if(c[i] == '1') fleg = 1;
		else flg = 1;
	}
	if(!flag || !fleg){
		printf("0");
		return 0;
	}
	if(!flg && mina > z){
		long long ans = 1;
		for(int i = 1; i <= n; i++) ans = (ans * i) % M;
		printf("%lld", ans);
	}
	if(m == 1){
		int cnt = 0, sum = 0;
		long long ans = 1;
		for(int i = 1; i <= n; i++){
			if(c[i] == '1'){
				sum = i;
				break;
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] >= sum) cnt++;
		}
		for(int i = 1; i < n; i++) ans = (ans * i) % M;
		ans = (ans * cnt) % M;
		printf("%lld", ans);
		return 0;
	}
	if(n == m){
		int f = 0;
		long long ans = 1;
		for(int i = 1; i <= n; i++){
			if(!a[i] || c[i] == '0') f = 1;
		}
		if(!f){
			for(int i = 1; i <= n; i++) ans = (ans * i) % M;
		}else ans = 0;
		printf("%lld", ans);
	}
	dfs(1);
	ans %= M;
	printf("%lld", ans);
	return 0;
}
