#include<bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 505 , mod =  998244353 ;

int n , m , s[N] , c[N] ;

int p[N] ;

int ans[N] ;

int res = 0;

int dp[1<<19][19][19] ;

bool vis[1<<19][19][19] ; 

inline int dfs(int nw,int fq,int S ) {
    if(vis[S][nw][fq]) return dp[S][nw][fq] ; 
    // cout << nw << ' ' << fq << " " << S << '\n' ;
    vis[S][nw][fq] = 1;
    if( nw - 1 - fq + n - nw + 1 < m ) return 0 ;
    if( nw - 1 - fq >= m ) {
        return dp[S][nw][fq] = ans[n - nw + 1 ] ;
    }// cout << "!" ;
    for(int i = 1 ; i <= n ; i ++ ) if( ! (S >> (i-1) & 1) ) {
        (dp[S][nw][fq] += dfs(nw + 1 , fq + (s[nw] == 0 || fq >= c[i] ) , S | (1<<i-1) ) ) %= mod ; 
    } return dp[S][nw][fq];
}

signed main() {
    freopen("employ.in","r",stdin) ;
    freopen("employ.out","w",stdout) ;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
    double t = clock() ; 
    cin >> n >> m ;
    string T ; cin >>  T; 
    for(int i = 1 ; i <= n ; ++ i ) {  s[i] = T[i-1] - '0' ;   }
    for(int i = 1 ; i <= n ; i ++ ) {   cin >> c[i] ; p[i] = i ;  }
    ans[0] = 1 ;
    for(int i = 1; i <= n ;i ++ ) ans[i] = ans[i-1] * i % mod ;
    cout << dfs(1,0, 0) << '\n';
    return 0 ;
}