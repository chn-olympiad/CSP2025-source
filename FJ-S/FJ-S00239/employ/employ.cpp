#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, m, c[505], go, ple, at, k;
bool vis[505];
char s[505];
long long ans, cnt;
void dfs(int now){
	if(go > k)return;
	if(at >= m){
		cnt = 1;
		for(int i = 1; i <= n - ple; i++){
			cnt *= i;
			cnt %= N;
		}
		ans += cnt;
		ans %= N;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(go >= c[i]){
				vis[i] = 1;
				ple++;go++;
				dfs(i);
				vis[i] = 0;
				go--;
				ple--;
				continue;
			}
			vis[i] = 1;
			ple++;
			if(s[ple] == '1')at++;
			else go++;
			dfs(i);
			vis[i] = 0;
			if(s[ple] == '1')at--;
			else go--;
			ple--;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	k = n - m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	ans = 0;
	for(int i = 1; i <= n; i++){
		if(go >= c[i]){
			vis[i] = 1;
			ple++;go++;
			dfs(i);
			vis[i] = 0;
			go--;
			ple--;
			continue;
		}
		ple++;
		vis[i] = 1;
		if(s[ple] == '1')at++;
		else go++;
		dfs(i);
		if(s[ple] == '1')at--;
		else go--;
		vis[i] = 0;
		ple--;
	}
	printf("%lld", ans);
	return 0;
}

