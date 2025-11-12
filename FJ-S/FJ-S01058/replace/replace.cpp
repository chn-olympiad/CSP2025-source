#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 1) + (s << 3) + ch - 48);
	return s * w;
}
const int N = 5000005, M = 200005;
const int b1 = 131, P1 = 1e9 + 9, b2 = 137, P2 = 998244353;
int n, Q, sz[M], t1[M], t2[M];
int hsh1[M], hsh2[M], h01[M], h02[M], h11[M], h12[M];
int hs1[N], hs2[N], pw1[N], pw2[N];
char s[2][N];
il int hash1(int l, int r){return (hs1[r] - 1ll * hs1[l - 1] * pw1[r - l + 1] % P1 + P1) % P1;}
il int hash2(int l, int r){return (hs2[r] - 1ll * hs2[l - 1] * pw2[r - l + 1] % P2 + P2) % P2;}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = rd(), Q = rd(), pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= N - 5; i++) pw1[i] = 1ll * pw1[i - 1] * b1 % P1;
	for (int i = 1; i <= N - 5; i++) pw2[i] = 1ll * pw2[i - 1] * b2 % P2;
	for (int i = 1; i <= n; i++){
		scanf ("%s %s", s[0] + 1, s[1] + 1);
		int m = strlen(s[0] + 1);
		sz[i] = m;
		for (t1[i] = 1; t1[i] <= m && s[0][t1[i]] == s[1][t1[i]]; t1[i]++);
		for (t2[i] = m; t2[i] >= 1 && s[0][t2[i]] == s[1][t2[i]]; t2[i]--);
		for (int j = 1; j <= m; j++) hsh1[i] = (1ll * hsh1[i] * b1 % P1 + s[0][j]) % P1;
		for (int j = 1; j <= m; j++) hsh2[i] = (1ll * hsh2[i] * b2 % P2 + s[0][j]) % P2;
		for (int j = t1[i]; j <= t2[i]; j++) h01[i] = (1ll * h01[i] * b1 % P1 + s[0][j]) % P1;
		for (int j = t1[i]; j <= t2[i]; j++) h02[i] = (1ll * h02[i] * b2 % P2 + s[0][j]) % P2;
		for (int j = t1[i]; j <= t2[i]; j++) h11[i] = (1ll * h11[i] * b1 % P1 + s[1][j]) % P1;
		for (int j = t1[i]; j <= t2[i]; j++) h12[i] = (1ll * h12[i] * b2 % P2 + s[1][j]) % P2;
	}
	for (; Q--;){
		scanf ("%s %s", s[0] + 1, s[1] + 1);
		int m = strlen(s[0] + 1), p1, p2;
		for (int i = 1; i <= m; i++) hs1[i] = (1ll * hs1[i - 1] * b1 % P1 + s[0][i]) % P1;
		for (int i = 1; i <= m; i++) hs2[i] = (1ll * hs2[i - 1] * b2 % P2 + s[0][i]) % P2;
		for (p1 = 1; p1 <= m && s[0][p1] == s[1][p1]; p1++);
		for (p2 = m; p2 >= 1 && s[0][p2] == s[1][p2]; p2--);
		int ans = 0, H01 = 0, H02 = 0, H11 = 0, H12 = 0;
		for (int j = p1; j <= p2; j++) H01 = (1ll * H01 * b1 % P1 + s[0][j]) % P1;
		for (int j = p1; j <= p2; j++) H02 = (1ll * H02 * b2 % P2 + s[0][j]) % P2;
		for (int j = p1; j <= p2; j++) H11 = (1ll * H11 * b1 % P1 + s[1][j]) % P1;
		for (int j = p1; j <= p2; j++) H12 = (1ll * H12 * b2 % P2 + s[1][j]) % P2;
		for (int i = 1; i <= n; i++) if (t2[i] - t1[i] == p2 - p1){
			if (H01 != h01[i] || H11 != h11[i]) continue;
			if (H02 != h02[i] || H12 != h12[i]) continue;
			int pl = p1 - t1[i] + 1, pr = pl + sz[i] - 1;
			if (hash1(pl, pr) != hsh1[i]) continue;
			if (hash2(pl, pr) != hsh2[i]) continue;
			ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}

