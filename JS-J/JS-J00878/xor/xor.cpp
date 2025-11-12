#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k, a[N], cnt;

int main() {
    freopen( "xor.in", "r", stdin );
    freopen( "xor.out", "w", stdout );
    cin >> n >> k;
    for ( int i = 1; i <= n; ++i ) {
        cin >> a[i];
    }
    if ( k == 0 ) {
        int cnt = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( a[i] == 0 ) cnt++;
            else if ( a[i] == a[i + 1] ) {
                cnt++;
                i++;
            }
        }
        cout << cnt;
    } else if ( k == 1 ) {
        int cnt = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( a[i] == 1 ) cnt++;
        }
        cout << cnt;
    }
    return 0;
}
