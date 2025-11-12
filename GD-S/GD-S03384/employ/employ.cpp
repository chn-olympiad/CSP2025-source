#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
int n, m;
ll ans = 0;
string s;
vector <int> c(110);
void dfs(int num, int p, int q, vector <bool> &vis){
	if(num > n){
		if(p >= m) ans = (ans + 1) % mod;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]) continue;
		vis[i] = false;
		if(q >= c[i] || s[num - 1] == '0')
			dfs(num + 1, p, q + 1, vis);
		else
			dfs(num + 1, p + 1, q, vis);
		vis[i] = true;
	}
	return ;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	vector <bool> vis(n+1, true);
	dfs(1, 0, 0, vis);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
