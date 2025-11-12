#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen( "number.in", "r", stdin );
    freopen( "number.out", "w", stdout );
    string s;
    cin >> s;
    vector<int> num;
    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] >= '0' && s[i] <= '9' ) {
            num.push_back( s[i] - '0' );
        }
    }
    sort( num.begin(), num.end() );
    reverse( num.begin(), num.end() );
    for ( auto n : num ) {
        cout << n;
    }
    return 0;
}
