#include<bits/stdc++.h>
using namespace std;

int n;
int sum[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for ( int i = 0; i < n; i++ ) {
		if ( s[i] >= '0' && s[i] <= '9' ) {
			sum[int(s[i] - '0')]++;
		}
	}
	for ( int i = 9; i >= 0; i-- ) {
		while ( sum[i]-- ) {
			cout << i;
		}
	}
	return 0;
}
