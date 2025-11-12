#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 505, mod = 998244353;

int n, m;
int a[N], c[N];

int p[N]; 

int solve1() {
	for (int i = 1; i <= n; i++) p[i] = i;
	int ans = 0; 
	do {
		int bad = 0;
		for (int i = 1; i <= n; i++)
			if (!a[i] || bad >= c[p[i]]) bad++;
		if (n - bad >= m) ans = (ans + 1) % mod;
	} while (next_permutation(p + 1, p + 1 + n));
	cout << ans << "\n";
	return 0;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m; bool A = 1;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		a[i] = c - '0';
		A &= a[i]; 
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	
//	if (A) {
//		 
//	}
	
	if (n <= 10) return solve1();
	return 0;
}
/*
3 2
101
1 1 2
output:2 
*/
