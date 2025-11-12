#include <bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N = 4e5 + 9 ;
int n , q ;
struct node{
    string s1 , s2 ;
    int len1 , len2 ;
}a[N] ;
string t1 , t2 ;
int p[N] , nex[N] , nex2[N] ;
bool pre[N] , bac[N] ;
int ans ; 
void work ( int size1 , int size2 ){
    pre[0] = true ;
    bool f = false ;
    for ( int i = 0 ; i < size1 ; ++i ){
        if ( f == true ){ pre[i+1] = false ; continue ;}
        if ( t1[i] == t2[i] && !f ){
            pre[i+1] = true ;
        }else{
            f = true ;
        }   
    }
    f = false ;
    for ( int i = size1 ; i >= 0 ; --i ){
        if ( f == true ) {
            bac[i+1] = false ; continue ;
        }
        if ( t1[i] == t2[i] && !f ){
            bac[i+1] = true ;
        }else{
            f = true ;
        }
    }
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++i ){
        string st1 = " " + a[i].s1 + "%" + t1 ;
        string st2 = " " + a[i].s2 + "%" + t2 ;
        int l1 = a[i].len1 + 1 + size1 ;
        int l2 = a[i].len2 + 1 + size2 ;
        nex[1] = 0 ;
        int j = 0 ;
        for ( int k = 2 ; k <= l1 ; ++k ){
            while ( st1[j+1] != st1[k] && j ) j = nex[j] ;
            if ( st1[j+1] == st1[k] ){
                ++j ;
                nex[k] = j ;
                if ( nex[k] == a[i].len1 && bac[k+1-a[i].len1-1] && pre[k-a[i].len1-a[i].len1-1] ){
                    p[k] = 1 ;
                }else p[k] = 0 ;
            }
        }
        nex2[1] = 0 ;
        j = 0 ;
        for ( int k = 2 ; k <= l2 ; ++k ){
            while ( st2[j+1] != st2[k] && j ) j = nex2[j] ;
            if ( st2[j+1] == st2[k] ){
                ++j ;
                nex2[k] = j ;
                if ( nex2[k] == a[i].len2 ){
                    ans += p[k] ;
                }
            }
        }
    }
}
signed main ( ){
    freopen ( "replace.in" , "r" , stdin ) ;
    freopen ( "replace.out" , "w" , stdout ) ;
    IOS ;
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++i ){
        cin >> a[i].s1 >> a[i].s2 ;
        a[i].len1 = a[i].s1.size( ) , a[i].len2 = a[i].s2.size( ) ; 
    }
    while ( q-- ){
        cin >> t1 >> t2 ;
        work ( t1.size ( ) , t2.size ( ) ) ;
        cout << ans << "\n" ;
    }
    return 0 ;
}