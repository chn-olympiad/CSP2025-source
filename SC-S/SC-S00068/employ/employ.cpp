#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 20, mod = 998244353;
int n, m, ans = 0, s[maxn], p[maxn], c[maxn];
void check() {
	int noused = 0;
	for(int i = 1; i <= n; ++ i) {
		if(c[p[i]] <= noused || s[i] == 0) ++ noused; 
		if(i - noused == m) {++ ans; return;}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	if(n <= 10) {
		char akioi;
		for(int i = 1; i <= n; ++ i) cin >> akioi, s[i] = akioi - '0';
		for(int i = 1; i <= n; ++ i) cin >> c[i];
		int num = 1;
		for(int i = 1; i <= n; ++ i) num *= i, p[i] = i;
		for(int i = 1; i <= num; ++ i) {
			check();
			if(i != num) next_permutation(p + 1, p + n + 1); 
		}
		cout << ans % mod;
	}
	else {
		cout << 0;
	}
}