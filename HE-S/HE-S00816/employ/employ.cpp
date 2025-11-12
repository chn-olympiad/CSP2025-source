#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 15;
int n,m;
int p[maxn];
string s;
int ans = 0;
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	int op[14];
	for (int i = 1; i <= n; i++) cin >> p[i],op[i] = i;
	do{
		int a[14];
		for (int i = 1; i <= n; i++) a[i] = p[op[i]];
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= a[i]) ++cnt;
			else if (s[i] == '0') ++cnt;
		}
		if (n-cnt >= m) ++ans;
		if (ans >= mod) ans -= mod;
	}while (next_permutation(op+1,op+n+1));
	cout << ans << '\n';
	return 0;
}
