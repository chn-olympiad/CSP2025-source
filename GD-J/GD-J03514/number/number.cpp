#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string s;
int t;
int nums[ N ];

bool comp (int x, int y) {
	return x > y;
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false);
	
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		char c = s[ i ];
		
		if ( '0' <= c and c <= '9' ) {
			nums[ ++t ] = (int)(c - '0');
		}
	}
	
	sort( nums + 1 , nums + t + 1 , comp );
	
	for (int i = 1; i <= t; i++) {
		cout << nums[ i ];
	}
	return 0;
} 
