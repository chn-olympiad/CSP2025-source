#include <bits/stdc++.h>
using namespace std;

int n,m,c[505];
long long ans = 1,p = 998244353;
string s;

int main() {
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++) cin >> c[i];
	for (int i = 1;i <= n;i++)
		if (!c[i]) m++;
	if (n < m) {cout << 0 << endl;return 0;}
	for (int i = 1;i <= n;i++) ans = ans * i % p;
	cout << ans << endl;
	return 0;
}