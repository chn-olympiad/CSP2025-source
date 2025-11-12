#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 55;
const int mod = 998244353;

int n, m, ans = 0;
int vs[max_n], a[max_n];
string s;

void dfs(int x, int y, int z) {
	if (x > n) {
		if (y >= m) {
			ans = (ans + 1) % mod;
		}
		
		return ;
	}
	
	if (z >= n - m)
		return ;
	
	for (int i = 1; i <= n; i++) {
		if (vs[i])
			continue;
			
		vs[i] = 1;
		
		if (s[i] == '0' || z >= a[i])
			dfs(x + 1, y, z + 1);
		else 
			dfs(x + 1, y + 1, z);
		
		vs[i] = 0;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	cin >> s;
	
	s = " " + s;
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	dfs(1, 0, 0);
	
	printf("%d", ans);
	
	return 0;
}