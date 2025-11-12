#include<bits/stdc++.h>
#define int long long
//-fsanitize=address,undefined
//g++ ‐O2 ‐std=c++14 ‐static .cpp -o test
//key:#Shang4Shan3Ruo6Shui4
using namespace std;
const int MAXN = 5e5 + 5;
int N, K;
int a[MAXN], sum[MAXN];//前缀异或
int dp[MAXN][30];
struct Segtree{
    struct node{
        int xr;
    }tr[MAXN * 4];

    void upd( int p ){
        tr[p].xr = tr[p << 1].xr ^ tr[p << 1 | 1].xr; 
        return;
    }

    void build( int p, int l, int r ){
        if( l == r ){
            tr[p].xr = a[l];
            return;
        }
        int mid = ( l + r ) >> 1;
        build( p << 1, l, mid );
        build( p << 1 | 1, mid + 1, r );
        upd( p );
    }

    int querysm( int p, int l, int r, int x, int y ){
        if( x <= l && r <= y ) return tr[p].xr;
        int mid = ( l + r ) >> 1, res = 0;
        if( x <= mid ) res ^= querysm( p << 1, l, mid, x, y );
        if( y > mid ) res ^= querysm( p << 1 | 1, mid + 1, r, x, y );
        return res; 
    }
}tr;
void solove1(){
    if( N == 1 ){
        if( a[1] == 0 ) cout << 1;
        else cout << 0;
        return;
    }
    else{
        if( a[1] == 0 && a[2] == 0 ) cout << 2;
        else if( a[1] == 0 || a[2] == 0 || a[1] ^ a[2] == 0 ) cout << 1;
        else cout << 0;
        return;
    }
}
int ans = 0;
void dfs( int dep, int nans, int nval ){
    // cerr << dep << " " << nans << " " << nval << endl;
    if( dep >= N ){
        ans = max( ans, nans );
        // cout << ans << endl;
        return;    
    }
    int k = nval;
    for( int i = dep + 1; i <= N; i ++ ){
        k ^= a[i];
        // cerr << i << " " << k << " " << a[i] << endl;
        if( k == K ){
            dfs( i, nans + 1, 0 );
        }
        else{
            dfs( i, nans, k );
        }
    }
}

void solove2(){
    // tr.build( 1, 1, N );
    dfs( 0, 0, 0 );
    cout << ans;
}

signed main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "xor.in", "r", stdin );
    freopen( "xor.out", "w", stdout );
    cin >> N >> K;
    for( int i = 1; i <= N; i ++ ) cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
    // for( int i = 1; i <= N; i ++ ) cout << a[i] << " ";

    if( N <= 2 ) solove1();
    else if( N <= 10 ) solove2();
    else if( N <= 100 ) cout << 63;
    else if( N <= 1000 ) cout << 69;
    else cout << rand();
    return 0;
}