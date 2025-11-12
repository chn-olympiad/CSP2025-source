#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int MOD = 998244353;
int l[N], n, cnt = 0;
vector<int> res;
map<vector<int>, bool> mp;
void dfs( int idx, int sum, int maxv, vector<int> res ) {
    if ( idx == n - 1 && sum == 0 ) return;
    if ( sum > maxv * 2 && !mp[res] ) {
        cnt = ( cnt + 1 ) % MOD;
        mp[res] = true;
    }
    if ( idx > n ) return;
    dfs( idx + 1, sum, maxv, res );
    vector<int> cur = res;
    res.push_back( idx );
    dfs( idx + 1, sum + l[idx], l[idx], res );
    res = cur;
}
int main() {
    freopen( "polygon.in", "r", stdin );
    freopen( "polygon.out", "w", stdout );
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> l[i];
    }
    sort( l + 1, l + n + 1 );
    dfs( 1, 0, 0, res );
    cout << cnt << "\n";
    return 0;
}
