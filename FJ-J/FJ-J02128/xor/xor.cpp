#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
using namespace std;

inline int rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int t[2000006], d[500005], a[500005], f[500005], lst[500005];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = rd(), k = rd();
	for(int i = 1; i <= n; i++) d[i] = (d[i - 1] ^ (a[i] = rd()));
	t[0] = 0;
	for(int i = 1; i <= n; i++) {
		lst[i] = t[d[i] ^ k];
		if(d[i] != k && !lst[i]) lst[i] = -1;
		t[d[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if(lst[i] >= 0) f[i] = max(f[i], f[lst[i]] + 1); 
	}
	cout << f[n];
	return 0;
}
/*
先把 $a_i$ 做前缀异或和。 

设 $f_i$ 表示到 $i$ 的最大贡献，令 $lst_i$ 最大，满足 $d_i ^ d_{lst_i} = k$。

则有 $f_i = \max(f_i, f_{lst_i} + 1)$。 
*/

