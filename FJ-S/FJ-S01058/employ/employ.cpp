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
const int N = 505, P = 998244353;
int n, m, sum, f[(1 << 18) + 5][20], c[N];
char ch[N];
il void cx(int &x, int y){x = (x + y) % P;}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = rd(), m = rd(), scanf ("%s", ch + 1);
	for (int i = 1; i <= n; i++) c[i] = rd(), sum += ch[i] - '0';
	if (m == n){
		if (sum < n) return puts("0"), 0;
		int flg = 0;
		for (int i = 1; i <= n; i++) flg |= (c[i] == 0);
		if (flg) return puts("0"), 0;
		int ans = 1;
		for (int i = 1; i <= n; i++) ans = 1ll * ans * i % P;
		return printf ("%d\n", ans), 0;
	}
	f[0][0] = 1;
	for (int s = 0; s < (1 << n) - 1; s++) for (int j = 0; j <= n; j++) if (f[s][j]){
		int i = 0;
		for (int k = 0; k < n; k++) i += ((s >> k) & 1);
		for (int k = 1; k <= n; k++) if (!((s >> (k - 1)) & 1)){
			if (c[k] <= i - j || ch[i + 1] == '0') cx(f[s | (1 << (k - 1))][j], f[s][j]);
			else cx(f[s | (1 << (k - 1))][j + 1], f[s][j]);
		}
	}
	int ans = 0;
	for (int i = m; i <= n; i++) cx(ans, f[(1 << n) - 1][i]);
	printf ("%d\n", ans);
	return 0;
}

