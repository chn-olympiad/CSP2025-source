#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define int ll

const int N = 100000 + 10;
const int inf = 998244353;
using namespace std;

int read () {
	int x = 0, k = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') k = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * k;
}

int n, m, ret, s[N], a[N], p[N]; char c;

bool check () {
	int cnt = 0, knt = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 0 || cnt >= a[p[i]]) ++cnt;
		else ++knt;
	}
	return knt >= m;
}

signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) cin >> c, s[i] = (c ^ '0');
	for (int i = 1; i <= n; ++i) a[i] = read(), p[i] = i;
	do { ret += check(); } while (next_permutation(p + 1, p + 1 + n));
	cout << ret % inf << endl;
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
AFO 18:02
*/

