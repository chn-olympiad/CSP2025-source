#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, c[505], sum[505];
int vis[505];
long long ans;
string s;
void dfs(int x, int q){
	if(q > n - m)return;
	if(x > n){
		if(n - q >= m){
			ans++;
			ans %= p;
		}
		
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		vis[i] = x;
		if(c[i] <= q || s[x] == '0')dfs(x + 1, q + 1);
		else dfs(x + 1, q);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++)scanf("%d", c + i);
//	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++)sum[c[i]]++;
	for(int i = 1; i <= 500; i++)sum[i] += sum[i - 1];
	bool t = 1;
	s = "0" + s;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			t = 0;
		}
	}
	if(n == m){
		if(!t){
			printf("0");
			return 0;
		}
	}
	if(t){
		ans = 1;
		for(int i = 0; i < n; i++){
			ans *= (n - i);
			ans &= p;
		}
		printf("%lld\n", ans);
		return 0;
	}
	if(n <= 18)dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
