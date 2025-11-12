#include<bits/stdc++.h>
#define N 507
#define ll long long
#define MOD 998244353
using namespace std;
int n, m;
bool s[N];
int c[N], ind[N];
bool use[N];
ll jc[N], ans = 0;
void dfs(int u){
	if(u >= n){
		int fail = 0;
		for(int i = 1;i <= n;i++){
			if(fail >= c[ind[i]] || !s[i])fail++;
		}
		//cout << fail << ' ';
		if(n - fail >= m){
			ans ++;
			ans %= MOD;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!use[i]){
			use[i] = 1;
			ind[u + 1] = i;
			dfs(u + 1);
			use[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		char ch;
		cin >> ch;
		s[i] = ch == '1';
		ind[i] = i;
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}
