#include<bits/stdc++.h>
using namespace std;
const int MAXN = 510;
const int mod = 998244353;
int a[MAXN];
bool b[MAXN];
bool vis[MAXN];
int p[MAXN];
int n, m, ans;
void dfs(int x){
	if(x > n){
		int sum = 0, cnt = 0;
		for(int i = 1; i <= n; i++){
			if(sum >= a[p[i]]){
				sum++;
				continue;
			}
			if(!b[i]){
				sum++;
			}
			else{
				cnt++;
			}
		}
		if(cnt >= m){
			ans++;
			if(ans > mod){
				ans -= mod;
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		if(c == '1'){
			b[i] = true;
		}
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}