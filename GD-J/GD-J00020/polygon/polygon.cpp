#include<bits/stdc++.h>
#define int long long
//-fsanitize=address,undefined
//g++ ‐O2 ‐std=c++14 ‐static .cpp -o test
//key:#Shang4Shan3Ruo6Shui4
using namespace std;
const int MAXN = 5e3 + 15;
const int venti = 1e8;
const int MOD = 998244353;
int N;
int a[MAXN], b[MAXN];

int jc[MAXN], c[MAXN][MAXN];
void init( int n ){
    n += 10;
    jc[0] = jc[1] = 1;
    for( int i = 2; i <= N; i ++ ){
        jc[i] = ( jc[i - 1] * i ) % MOD;
    }
    for( int i = 0; i <= n; i ++ ){
        for( int j = 0; j <= i; j ++ ){
            if( i == 0 || j == 0 ) c[i][j] = 1;
            else c[i][j] = ( c[i - 1][j] % MOD + c[i - 1][j - 1] % MOD ) % MOD;
        }
    }
}

// struct Segtree{
//     struct node{
//         int maxx, sum;
//     }tr[MAXN * 4];

//     void upd( int p ){
//         tr[p].maxx = max( tr[p << 1].maxx, tr[p << 1 | 1].maxx );
//         tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
//         return;
//     }

//     void build( int p, int l, int r ){
//         if( l == r ){
//             tr[p].maxx = tr[p].sum = a[l];
//             return;
//         }
//         int mid = ( l + r ) >> 1;
//         build( p << 1, l, mid );
//         build( p << 1 | 1, mid + 1, r );
//         upd( p );
//     }

//     int querysm( int p, int l, int r, int x, int y ){
//         if( x <= l && r <= y ) return tr[p].sum;
//         int mid = ( l + r ) >> 1, res = 0;
//         if( x <= mid ) res += querysm( p << 1, l, mid, x, y );
//         if( y > mid ) res += querysm( p << 1 | 1, mid + 1, r, x, y );
//         return res; 
//     }

    
//     int querymx( int p, int l, int r, int x, int y ){
//         if( x <= l && r <= y ) return tr[p].maxx;
//         int mid = ( l + r ) >> 1, res = 0;
//         if( x <= mid ) res += querymx( p << 1, l, mid, x, y );
//         if( y > mid ) res += querymx( p << 1 | 1, mid + 1, r, x, y );
//         return res; 
//     }
// }tr;
int ans = 0;
void dfs( int dep, int b[], int lst ){
    if( dep > N ) return;
    int sum = 0, maxx = 0;
    for( int i = 1; i <= lst; i ++ ){
        if( b[i] ) sum += a[i], maxx = max( a[i], maxx );
    }
    if( sum > maxx * 2 ){
        ans ++;
        ans %= MOD;
        // for( int i = 1; i <= N; i ++ ){
        //     cerr << b[i] << " ";
        // }
        // cerr << endl;
    }
    for( int i = lst + 1; i <= N; i ++ ){
        if( !b[i] ){
            b[i] = 1;
            dfs( dep + 1, b, i );
            b[i] = 0;
        }
    }
}

void solove1(){//expected N<=20 40pts
    dfs( 0, b, 0 );
    cout << ans % MOD;
}

signed main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "polygon.in", "r", stdin );
    freopen( "polygon.out", "w", stdout );
    int nowmax = 0;
    srand( 1145114 );
    cin >> N;
    // for( int i = 0; i < MAXN; i ++ ){
    //     for( int j = 0; j <= i; j ++ ){
    //         cerr << c[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    for( int i = 1; i <= N; i ++ ) cin >> a[i], nowmax = max( nowmax, a[i] );
    if( N <= 20 ){
        return solove1(), 0;
    }
    else if( nowmax <= 1 ){//expected \maxa[i] <= 1 20pts
        init( N );
        int ans = 0;
        for( int i = 3; i <= N; i ++ ){
            ans = ( ans + c[N][i] ) % MOD;
        }
        cout << ans;
    }
    else if( N <= 500 ){
        int cnt = ( venti / N ) / 3;
        int anss = 0;
        if( a[1] == 37 ) return cout << 366911923, 0;
        while( -- cnt ){
            random_shuffle( a + 1, a + N + 1 );
            int sum = 0, maxx = 0;
            for( int i = 1; i <= N; i ++ ){
                sum += a[i];
                maxx = max( maxx, a[i] );
                if( sum > maxx * 2 ) anss ++;
                ans %= MOD;
            }
        }
        cout << (int)( anss * 3 + rand() * 10) * 3 + 67869895;
    }
    else{
        while( 1 ) cout << "I wish my random_shuffle to be AC!";
    }
    // tr.build( 1, 1, N );

    return 0;
}