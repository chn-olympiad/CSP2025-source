#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int n, m;
int a[509];
bitset<509> c;
bitset<509> f;
int cnt;

int jc(int x) {
	int ans = 1;
	for(int i = 2; i <= x; i++) {
		ans = 1LL * ans * i % mod;
	}
	return ans;
}

void dfs(int u, int s, int d) {
	if(d >= m) {
		cnt += jc(n - u + 1);
		cnt %= mod; 
		return;	
	}
//	if(u > n && d >= m) {
//		cnt++;
//		cnt %= mod;
//		return;
//	}
	if(u > n) {
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(f[i]) continue;
		f[i] = 1;
		if(s < a[i] && c[u]) dfs(u + 1, s, d + 1);
		else dfs(u + 1, s + 1, d);
		f[i] = 0;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	string p;
	cin >> p;
	for(int i = 0; i < n; i++) {
		c[i + 1] = p[i] - '0';
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	sort(a + 1, a + n + 1);
//	reverse(a + 1, a + n + 1);
	dfs(1, 0, 0);
	cout << cnt << "\n";
	
	
	return 0; 
}
