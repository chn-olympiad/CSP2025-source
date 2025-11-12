#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 998244353;

int n, m, ans, c[501];
string s;
bool vis[501];

void dfs(int k, int dist, int fired){
	if(dist + n - k + 1 < m) return;
	if(k > n){
		if(dist >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[k - 1] == '0'){
			dfs(k + 1, dist, fired + 1);
		}
		else{
			if(fired >= c[i]) dfs(k + 1, dist, fired + 1);
			else dfs(k + 1, dist + 1, fired);
		}
		vis[i] = 0; 
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &c[i]);
	}
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}

/*
3 2
101
1 1 2
*/

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
