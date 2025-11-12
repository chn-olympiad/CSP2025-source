#include<bits/stdc++.h>
using namespace std;
const int N = 15;
const int M = 15;
int val[N * M], n, m, res[N][M];

int main() {
    freopen( "seat.in", "r", stdin );
    freopen( "seat.out", "w", stdout );
    cin >> n >> m;
    for ( int i = 1; i <= n * m; ++i ) {
        cin >> val[i];
    }
    int k = val[1];
    sort( val + 1, val + n * m + 1, greater<int>() );
    int x = 1, go = 1, idx = 1;
    for ( int i = 1; i <= m; ++i ) {
        for ( int j = 1; j <= n; ++j ) {
            if ( i % 2 == 1 ) x = j;
            else x = n - j + 1;
            res[x][i] = val[idx++];
        }
    }
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= m; ++j ) {
            if ( res[i][j] == k ) {
                cout << j << " " << i << "\n";
                break;
            }
        }
    }
    return 0;
}
