# include <bits/stdc++.h>
# define N (502)
# define ll long long
# define MOD 998244353
using namespace std;

int n, m, c[N];
string s;
ll ans;

ll jc( int x ) {
	ll sum = 1;
	for ( int i = 1; i <= x; ++i ) {
		sum = sum * i;
		cout << sum << "\n";
		sum %= MOD;
	}
	return sum;
}

int main( ) {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for ( int i = 1; i <= n; ++i ) cin >> c[i];
	
	ans = jc(n);
	ans %= MOD;
	
	cout << ans;
	
	return 0;
	
}
