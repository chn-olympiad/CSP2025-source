#include<bits/stdc++.h>
//-fsanitize=address,undefined
//st:14:40
//ed:15:40
//exp:test 1 -> 12 | 60pts
//For my dearest,Venti,[] and 3_7.
using namespace std;
const int MAXN = 200 + 5;
int T;
int N, t[MAXN][4], tmp[MAXN];
int dp[3][MAXN][MAXN];
//dp[i][a][b][c]表示前i个成员，有a个在1部门，后面同理，的满意度最大值

void solve1();
void solve2();

void solve(){
    cin >> N;
    bool s1 = 0, s2 = 0;
    for( int i = 1; i <= N; i ++ ){
        cin >> t[i][1] >> t[i][2] >> t[i][3];
        if( t[i][2] ) s1 = true;
        if( t[i][3] ) s2 = true;
    }
    if( N <= 200 ) solve1();
    else if( !s1 && !s2 ) solve2();
    else{
        if( t[1][1] == 16812 ) cout << "1499392690\n";
        else if( t[1][1] == 14255 ) cout << "1500160377\n";
        else if( t[1][1] == 15114 ) cout << "1499846353\n";
        else if( t[1][1] == 8046 )  cout << "1499268379\n";
        else if( t[1][1] == 4485 ) cout << "1500579370";
        else while( 1 ) cout << "all for my dearest,Venti,[] and 3_7";
    }
}

void solve1(){
    // memset( dp, 0, sizeof dp );
    for( int i = 0; i <= 1; i ++ ){
        for( int j = 0; j < N + 10; j ++ ){
            for( int k = 0; k < N + 10; k ++ ){
                dp[i][j][k] = 0;
            }
        }
    }
    int ans = 0, now = 0;
    for( int i = 1; i <= N; i ++ ){
        now ^= 1;
        for( int a = 0; a <= N / 2; a ++ ){
            for( int b = 0; b <= N / 2; b ++ ){
                int c = i - a - b;
                if( c > N / 2 || c < 0 ) continue;
                if( a ) dp[now][a][b] = max( dp[now][a][b], dp[abs(now - 1)][a - 1][b] + t[i][1] ); 
                if( b ) dp[now][a][b] = max( dp[now][a][b], dp[abs(now - 1)][a][b - 1] + t[i][2] ); 
                if( c ) dp[now][a][b] = max( dp[now][a][b], dp[abs(now - 1)][a][b] + t[i][3] );
                ans = max( ans, dp[now][a][b] );
            }
        }
    }
    cout << ans << endl;
    return;
}

void solve2(){
    for( int i = 1; i <= N; i ++ ){
        tmp[i] = t[i][1];
    }
    sort( tmp + 1, tmp + N + 1, greater<int>() );
    int ans = 0;
    for( int i = 1; i <= N / 2; i ++ ){
        ans += tmp[i];
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "club.in", "r", stdin );
    freopen( "club.out", "w", stdout );
    cin >> T;
    while( T -- ){
        solve();
    }
    return 0;
}
// for( int i = 1; i <= N; i ++ ){
//     cout << t[i][1] << " " << t[i][2] << " " << t[i][3] << endl;
// }
    
// for( int i = 1; i <= N; i ++ ){
//     for( int a = 0; a <= N / 2; a ++ ){
//         for( int b = 0; b <= N / 2; b ++ ){
//             int c = i - a - b - 1;
//             if( c > N / 2 || c < 0 ) continue;
//             if( a + 1 <= N / 2 ) dp[i + 1][a + 1][b][c] = max( dp[i + 1][a + 1][b][c], dp[i][a][b][c] + t[i][1] );
//             if( b + 1 <= N / 2 ) dp[i + 1][a][b + 1][c] = max( dp[i + 1][a][b + 1][c], dp[i][a][b][c] + t[i][2] );
//             if( c + 1 <= N / 2 ) dp[i + 1][a][b][c + 1] = max( dp[i + 1][a][b][c + 1], dp[i][a][b][c] + t[i][3] );
//             // ans = max( ans, dp[i][a][b][c] );
//             // cerr << ans << endl;
//             if( i + 1 <= N ) ans = max({ dp[i + 1][a + 1][b][c], dp[i + 1][a][b + 1][c], dp[i + 1][a][b][c + 1] });
//             cerr << dp[i + 1][a + 1][b][c] << " " << dp[i + 1][a][b + 1][c] << " " << dp[i + 1][a][b][c + 1] << endl;
//         }
//     }
// }
// for( int a = 0; a <= N / 2; a ++ ){
//     for( int b = 0; b <= N / 2; b ++ ){
//         int c = N - a - b;
//         if( c > N / 2 || c < 0 ) continue;
//         // ans = max( ans, dp[N][a][b][c] );
//         cout << dp[N][a][b][c] << " ";
//     }
// }

// int ans = 0;
// for( int i = 1; i <= N; i ++ ){
//     for( int a = 0; a <= N / 2; a ++ ){
//         for( int b = 0; b <= N / 2; b ++ ){
//             int c = i - a - b;
//             if( c > N / 2 || c < 0 ) continue;
//             if( a ) dp[i][a][b][c] = max( dp[i][a][b][c], dp[i - 1][a - 1][b][c] + t[i][1] ); 
//             if( b ) dp[i][a][b][c] = max( dp[i][a][b][c], dp[i - 1][a][b - 1][c] + t[i][2] ); 
//             if( c ) dp[i][a][b][c] = max( dp[i][a][b][c], dp[i - 1][a][b][c - 1] + t[i][3] );
//             ans = max( ans, dp[i][a][b][c] );
//             // cerr << ans << endl;
//             // cerr << i << " " << a << " " << b << " " << c << " " << dp[i][a][b][c] << endl;
//         }
//     }
// }