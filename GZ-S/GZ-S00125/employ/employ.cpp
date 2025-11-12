//GZ-S00125 贵阳市南明区李端棻中学 姜铭灿 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 998244353, MAXN = 5e2 + 5; 
int n, m, p[MAXN], c[MAXN], ans;
bool st[MAXN], used[MAXN];

bool check(){
	int cnt = 0, ret = 0;
	for(int i = 1; i <= n; i++) ret += (st[i] && c[p[i]] > cnt), cnt += !(st[i] && c[p[i]] > cnt); 
	return ret >= m;
}

void dfs(int pos){
	if(pos > n){
		ans = (ans + check()) % MOD;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(used[i]) continue;
		used[i] = 1, p[pos] = i;
		dfs(pos + 1);
		used[i] = 0;
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	char ch;
	for(int i = 1; i <= n; i++) cin >> ch, st[i] = ch - '0';
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
