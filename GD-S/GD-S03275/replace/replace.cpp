#include<bits/stdc++.h>
using namespace std;
int n , q , cnt , op , o[30];
map<string , string> mp;
map<pair<string,pair<string, string > > , int > opp; 
string s , s1;
int main() {
	freopen ( "replace.in" , "r" , stdin );
	freopen ( "replace.out" , "w" , stdout);
	cin >> n >> q;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> s >> s1;
		mp[s] = s1;
	}
	for ( int i = 1; i <= q ; i ++ ) {
		cin >> s >> s1;
		cnt = 0;
		int io = 0 , ioo = 0 , p = 0 ;
		for ( int j = 0 ; j < s.size() ; i ++ ) {
			if ( o[s[i] -'a'] == 0 ) p ++ ;
			if ( o[s[i] - 'a'] == 1 ) io = j;
		}
		if ( p == 2 ) {
			p = 0;
			for ( int j = 0 ; j < s1.size() ; i ++ ) {
				if ( o[s1[i] - 'a'] == 0 ) p ++ ;
				if ( o[s1[i] - 'a'] == 1 ) ioo = j;
			}
			if ( p == 2 ) {
				cout << 1;
			}
			continue;
		}
		for ( int j = 0 ; j < s.size() ; j ++ ) {
			string a ;
			for ( int k = j ; k <= s.size() ; k ++ ) {
				string x = s.substr( 0 , j );
				string y = s.substr( j , k - j );
				string z = s.substr( k , s.size() - k );
				string x1 = s1.substr( 0 , j );
				string y1 = s1.substr( j , k - j);
				string z1 = s1.substr( k , s1.size() - k );
				if ( mp[x] == x1 || x == x1 ) {
					if ( mp[x] == x1 && x != x1) {
						op ++;
					}
					if ( mp[y] == y1 || y == y1 ) {
						if ( mp[y] == y1 && y != y1 ) {
							op ++;
						}
						if ( mp[z] == z1 || z == z1 ) {
							if ( mp[z] == z1 && z != z1)  op ++;
							if ( op >= 2 ) {
								continue;
							}
							string u = x + y + z;
							if ( u == a ) {
								continue;
							} 
							cnt ++;
							a = u;
							
						}
					}
				}
				op = 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
