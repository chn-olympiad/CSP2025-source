#include<bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5  + 10 ;

int n , a[N][3]  , p[N][3]  ; 

vector<int> fr[3] ;

int ch[N] ; 

void solve() {
    cin >> n ;
    for(int i = 0 ; i < 3 ; i ++ ) fr[i].clear() ; 
    int sum = 0 ;
    for(int i = 1 ;i  <= n  ;i ++ ) {
        for(int j = 0; j < 3 ; j ++ ) cin >> a[i][j] , p[i][j] =j ; 
        sort(p[i],p[i]+3,[&](int x,int y){return a[i][x] > a[i][y] ; }) ;
        fr[p[i][0]].push_back(i) ;
        sum += a[i][p[i][0]] ; 
        ch[i] = a[i][p[i][0]] - a[i][p[i][1]] ;
    } // cout << sum << '\n' ;
    int mx = -1  ; 
    for(int i = 0 ; i < 3 ; i ++ ) if( fr[i].size() > n / 2 ) mx = i ; 
    if(mx == -1 ) {
        cout<< sum << '\n' ;
        return ;
    }
    sort(fr[mx].begin(),fr[mx].end(),[&](int x,int y) { return ch[x] > ch[y] ;  }) ; 
    int T = fr[mx].size() - n / 2 ;
    // cout << T << '\n' ;
    while ( T -- ) {
        sum -= ch[fr[mx].back()] ; fr[mx].pop_back() ;
    } cout << sum << '\n' ;

}

signed main() {    
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
    int t; 
    cin >> t ;
    while ( t -- ) solve() ; 
    return 0 ;
}