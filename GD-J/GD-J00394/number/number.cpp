#include <bits/stdc++.h>

using namespace std;

const int qwe = 1e6 + 10;
string s;int a[qwe], t = 0;
bool cmp ( const int& x, const int& y ) {
	return x > y; 
}

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> s;
	for ( int i = 0;i < s.size(); i ++ ) {
		if ( s[i] >= '0' && s[i] <= '9' ) a[t ++] = s[i] - '0';
	}
	t --;
	//for ( int i = 0;i <= t; i ++ ) cout << a[i] << " ";
	sort ( a, a + t, cmp );
	for ( int i = 0; i <= t; i ++ ) {
		cout << a[i];
	}
	return 0;
}
