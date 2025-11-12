//CSP 2025 RP++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, mod = 998244353;
int n, m, ans, c[N], a[N]; char s[N];
bool vis[N];
void dfs(int idx){
	if(idx == n + 1){
		int tmp = 0;
		for(int i = 1, now = 0; i <= n; i++){
			if(s[i] == '0' || now >= c[a[i]]) now++;
			else tmp++;
		}
		if(tmp >= m) ans++;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = true, a[idx] = i;
			dfs(idx + 1);
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld\n%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
