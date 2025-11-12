#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105, mod = 998244353;
int n, m, a[N], ans[N], tot;
bool vis[N];
string s;
bool check(){
	int cnt = 0, res = 0;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == '0' || cnt >= a[ans[i]]) cnt++;
		else res++;
	}
	return res >= m;
}
void dfs(int x){
	if(x > n){
		tot += check();
		tot %= mod;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			ans[x] = i;
			dfs(x + 1);
			vis[i] = 0;
			ans[x] = 0;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << tot;
	return 0;
}
//8pts
