// GZ-S00427 °²Ë³¶þÖÐ ÕÔÑØ¿­ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++ i)
#define fir first
#define sec second

const int N = 1e5 + 10;
int n, a[N][4], p[N];
int f[210][210][210];

bool chk(int i, int j, int k) {
	if(j < 0 || k < 0 || i - j - k < 0)  return false;
	return j <= n / 2 && k <= n / 2 && i - j - k <= n / 2 && j + k <= i && i > 0 && (j > 0 || k > 0 || i - j - k > 0);
}

// O(n ^£³) 
int dp() {
	f[1][1][0] = a[1][1], f[1][0][1] = a[1][2], f[1][0][0] = a[1][3];
//	printf("f[%lld][%lld][%lld] = %lld\n", 1, 1, 0, f[1][1][0]);
//	printf("f[%lld][%lld][%lld] = %lld\n", 1, 0, 1, f[1][0][1]);
//	printf("f[%lld][%lld][%lld] = %lld\n", 1, 0, 0, f[1][0][0]);
	FOR(i, 2, n + 1) {
		FOR(j, 0, n) {
			FOR(k, 0, n) {
				if(!chk(i, j, k)) continue;
				if(chk(i - 1, j - 1, k)) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
				if(chk(i - 1, j, k - 1)) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
				if(chk(i - 1, j, k)) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);//printf("upd f[%lld][%lld][%lld], %lld + %lld\n", i, j, k, f[i - 1][j][k], a[i][3]);
//				printf("f[%lld][%lld][%lld] = %lld\n", i, j, k, f[i][j][k]);
			}
		}
	}
	int ans = 0;
	FOR(j, 0, n) FOR(k, 0, n) if(chk(n + 1, j, k)) ans = max(ans, f[n + 1][j][k]);
	return ans;
}

void clear() {
	memset(a, 0, sizeof(a)), memset(f, 0, sizeof(f)), memset(p, 0, sizeof(p));
	FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n) f[i][j][k] = 0;
}

int subA() {
	FOR(i, 1, n) p[i] = -a[i][1];
	sort(p + 1, p + n + 1);
	int ans = 0;
	FOR(i, 1, n / 2) ans += -p[i];
	return ans;
}

void Main() {
	int if_A = 1;
	clear();
	scanf("%lld", &n);
	FOR(i, 1, n)  {
		FOR(j, 1, 3) scanf("%lld", &a[i][j]);
		if(a[i][2] != 0 || a[i][3] != 0) if_A = 0;
	}
	if(if_A)  {
		printf("%lld\n", subA());
		return;
	}
	printf("%lld\n", dp());
	return;
}

signed main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	int T;
	scanf("%lld", &T);
	while(T --) Main();
	return 0;
}
