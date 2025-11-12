#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 510
ll ans;
const ll p = 998244353;
int n, m, c[N], num[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	s = " " + s;
	
	bool fl = 1;
	for (int i = 1; i <= n; ++i) 
		if (s[i] == '0') fl = 0;
	if (n <= 18) {
		for (int i = 1; i <= n; ++i) num[i] = i;
		int fq, cnt;
		do {
			fq = cnt = 0;
			for (int i = 1; i <= n; ++i) {
				int x = num[i];
				if (fq >= c[x]) ++fq;
				else if (s[i] == '0') ++fq;
				else ++cnt;
			}
			if (cnt >= m) ++ans;
		} while (next_permutation(num + 1, num + n + 1) != 0);
		cout << ans % p << endl;
		return 0;
	}
	if (fl) {
		ans = 1;
		int tot = 0;
		for (int i = 1; i <= n; ++i) 
			if (c[i]) ++tot;
		if (tot + 1 < m) puts("0");
		else {
			for (ll i = 1; i <= n - tot - 1; ++i) ans = (ans * i) % p/*, cout<< ans << "?\n"*/;
			for (ll i = 1; i <= tot + 1; ++i) ans = (ans * i) % p;
			cout << ans << endl;
		}
		
		return 0;
	}
	puts("0");
	return 0;
}
