#include<bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int n, m;
int c[600];
long long ans;
string s;
bool f[600];

void dfs(int i, int d, int ot, int in) {
	if ( in >= m ) {
		ans++;
		ans %= Mod;
	}
	for ( int j = 1; j <= n; j++ ) {
		if ( !f[j] ) {
			f[j] = 1;
			int ot_ = ot;
			if ( s[d + 1] == '0' || ot >= c[j] ) ot_++;
			dfs(j, d + 1, ot_, in + ( ot_ == ot ? 1 : 0 ));
			f[j] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for ( int i = 1; i <= n; i++ ) {
		cin >> c[i];
	}
	int ot = 0;
	if ( s[1] == '0' || !c[1] ) ot++;
	dfs(1, 1, ot, ( ot ? 0 : 1 ));
	cout << ans / 3;
	return 0;
}
