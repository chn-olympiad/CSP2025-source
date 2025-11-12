#include<bits/stdc++.h>
using namespace std;
const int N = 500, mod = 998244353;
int n, m, c[N];
long long ans = 0;
char s[N];
bool vis[N] = {0};
inline void dfs(int x, int sum){
	if(x == n+1){
		if(sum >= m){
			ans = (ans + 1)%mod;
		}
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(vis[i])continue;
		if(x - 1 - sum >= c[i] || s[x] == '0'){
			vis[i] = 1;
			dfs(x+1, sum);
			vis[i] = 0;
		} else {
			vis[i] = 1;
			dfs(x+1,sum+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> s[i];
	for(int i = 1;i <= n;i ++)
		cin >> c[i];
	dfs(1, 0);
	cout << ans;
	return 0;
}