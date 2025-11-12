#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
#define pp pop_back
//#define _x first
//#define _y second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 5e3 + 7, INF = 0x3f3f3f3f, MOD = 998244353;

void put(ll x, char el = '\n') {
	prt("%lld", x);
	putchar(el);
}

int a[N];
vector<int> b;
int n;
void dfs(int dep) {
	if (dep > n) {
		
	}	
}

int c[N][N];
int C(int n, int k){
	if (c[n][k] != 0) {
		return c[n][k] % MOD;
	}
	if (k == 0) return 0;
	if (n = 1 || k >= n) return 1;
	if (k = 1) return n;
	
	c[n][k] = C(n-1, k-2) + C(n-1, k-1) % MOD;
	return c[n][k];
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	c[1][1] = 1;
	c[n][1] = n;
	c[n][n] = 1;
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	sort(a+1,a+n+1);
	if (n == 3) put(1);
	put(C(3,2));
	if (mx == 1) {
		ll ans = 0;
		for (int i = 3; i <= n; i++) {
			ans += C(n, i) % MOD; 
		}
		put(ans);
	}
	
	
//	fclose(stdin); fclose (stdout);
	return 0;
}

