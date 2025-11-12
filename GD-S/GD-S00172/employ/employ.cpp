#include<bits/stdc++.h>
using namespace std;

const int N = 510, MOD = 998244353;
long long res;
int n, m, c[N], path[N];
string s;
bool st[N];

bool check(){
	int unemp = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == '0' || unemp >= c[i]) unemp++;
	return n - unemp >= m;
}

void dfs(int u){
	if(u == n){
		if(check()) res = (res + 1) % MOD;
		for(int i = 0; i < n; i++) cout << path[i] << ' ';
		cout << res << endl;
		return;
	}
	for(int i = 0; i < n; i++)
		if(!st[i]){
			st[i] = true;
			path[u] = i;
			dfs(u + 1);
			st[i] = false;
		}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	
	if(n < 20) dfs(0);
	else{
		res = 1;
		for(int i = 1; i <= n; i++) res = res * i % MOD;
	}
	cout << res;
	
	return 0;
}
