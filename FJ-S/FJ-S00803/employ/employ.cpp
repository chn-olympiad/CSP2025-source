#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long ans;
int n, m;
string s;
struct node {
	int num, c;
}a[100001];
bool cmp(node x, node y) {
	return x.num < y.num;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i ++) a[i].num = i;
	for(int i = 1; i <= n; i ++) cin >> a[i].c;
	do {
		int res = 0;
		for(int i = 1; i <= n; i ++) {
			if(res >= a[i].c || s[i] == '0') res ++;
		}
		if(res <= n - m) ans ++, ans %= mod;
	}while(next_permutation(a + 1, a + n + 1, cmp));
	printf("%lld", ans);
	return 0;
}
