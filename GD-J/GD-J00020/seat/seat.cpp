#include<bits/stdc++.h>
#define int long long
//-fsanitize=address,undefined
//g++ ‐O2 ‐std=c++14 ‐static .cpp -o test
//key:#Shang4Shan3Ruo6Shui4
using namespace std;
const int MAXN = 205;
int N, M;
// struct node{
//     int id, a;
// }
int a[MAXN];

// bool cmp( node a, node b ){
//     return a.a > b.a;
// }

signed main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    cin >> N >> M;
    freopen( "seat.in", "r", stdin );
    freopen( "seat.out", "w", stdout );
    for( int i = 1; i <= N * M; i ++ ){
        cin >> a[i];
        // a[i].id = i;
    }
    int now = a[1];
    sort( a + 1, a + N * M + 1, greater<int>() );
    int k = 0;
    for( int i = 1; i <= N * M; i ++ ){
        // cerr << a[i] << " ";
        if( a[i] == now ){
            k = i;
            // cerr << i << endl;
            break;
        }
    }
    // int k = upper_bound( a + 1, a + N * M + 1, now ) - a;

    // cout << k << endl;
    int b = k / N;
    if( k % N != 0 ) b ++;

    int c = k % N;
    if( c == 0 ) c = N;
    if( b % 2 == 0 ) c = N - c + 1;
    
    cout << b << " " << c;
    return 0;
}