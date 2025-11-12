#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
ll T , n , ans ;
struct person {
    ll a , b ,c ;
}tmp;
struct cmp1 {
    bool operator () ( person &a , person &b ) {
        if ( a.a != b.a ) return a.a > b.a ;
        else return (max(a.b,a.c)<max(b.b,b.c)) ;
    }
};
struct cmp2 {
    bool operator () ( person &a , person &b ) {
        if ( a.b != b.b ) return a.b > b.b ;
        else return (max(a.a,a.c)<max(b.a,b.c)) ;
    }
};
struct cmp3 {
    bool operator () ( person &a , person &b ) {
        if ( a.c != b.c ) return a.c > b.c ;
        else return (max(a.b,a.a)<max(b.b,b.a)) ;
    }
};
struct cmp4 {
    bool operator () ( person &a , person &b ) {
        int a1 = a.a , a2 = a.b , a3 = a.c ;
        int b1 = b.a , b2 = b.b , b3 = b.c ;
        if ( a1 < a2 ) swap(a1,a2) ;
        if ( a2 < a3 ) swap(a2,a3) ;
        if ( a1 < a2 ) swap(a1,a2) ;
        if ( b1 < b2 ) swap(b1,b2) ;
        if ( b2 < b3 ) swap(b2,b3) ;
        if ( b1 < b2 ) swap(b1,b2) ;
        if ( a1 > b1 ) return 0 ;
        else if ( a1 < b1 ) return 1 ;
        else {
            if ( a2 > b2 ) return 0 ;
            else if ( a2 < b2 ) return 1 ;
            else {
                return a3<b3 ;
            }
        }
    }
};
priority_queue <person,vector<person> ,cmp1> q1 ;
priority_queue <person,vector<person> ,cmp2> q2 ;
priority_queue <person,vector<person> ,cmp3> q3 ;
priority_queue <person,vector<person> ,cmp4> q4 ;
ll dp[310][310][310] ;
int main () {
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    //freopen("/home/noi/Desktop/club/club4.in","r",stdin) ;
    //freopen("/home/noi/Desktop/club/c.txt","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
    cin >> T ;
    while ( T-- ) {
        ans = 0 ;
        cin >> n ;
        if ( n <= 610 ) {
            memset(dp,0,sizeof dp) ;
            ll a , b , c ,answer=0 ;
            for ( ll x = 1 ; x <= n ; x ++ ) {
                cin >> a >> b >> c ;
                for ( int i = 0 ; i <= min(x,n/2) ; i ++ ) {
                    for ( int j = 0 ; j <= min(x-i,n/2) ; j ++ ) {
                        int k = x-i-j ;
                        if ( k > n/2 ) continue ;
                        if ( i != 0 ) {
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a) ;
                        }
                        if ( j != 0 ) {
                            dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+b) ;
                        }
                        if ( k != 0 ) {
                            dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]+c) ;
                        }
                        if ( x == n ) answer = max(answer,dp[i][j][k]) ;
                    }
                }
            }
            cout << answer << '\n' ;
        }else{
            bool flag = 1 ,pianfen=0;
        for ( int i = 1 ; i <= n ; i ++ ) {
            cin >> tmp.a >> tmp.b >> tmp.c ;
            if ( tmp.b != 0 || tmp.c != 0 ) flag = 0 ;
            q4.push(tmp) ;
        }
        if ( flag ){
                for ( int i = 1 ; i <= n/2 ; i ++ ) {
                    pianfen+=q4.top().a ;
                    q4.pop() ;
                }
            cout << pianfen << '\n' ;
            continue ;
        }
        while ( q4.size() ) {
            person tmp = q4.top() ;
            q4.pop() ;
            if ( tmp.a >= tmp.b && tmp.a >= tmp.c ) {
                if ( q1.size() < n/2 ) q1.push(tmp) ;
                else {
                    if ( (max(q1.top().b,q1.top().c)+tmp.a) > q1.top().a+max(tmp.b,tmp.c) ) {
                        q4.push(q1.top()) ;
                        q1.pop() ;
                        q1.push(tmp) ;
                    }else {
                        if ( tmp.b > tmp.c ) q2.push(tmp) ;
                        else q3.push(tmp) ;
                    }
                }
            } else if ( tmp.b >= tmp.a && tmp.b >= tmp.c ) {
                if ( q2.size() < n/2 ) q2.push(tmp) ;
                else {
                    if ( (max(q2.top().a,q2.top().c)+tmp.b) > q2.top().b+max(tmp.a,tmp.c) ) {
                        q4.push(q2.top()) ;
                        q2.pop() ;
                        q2.push(tmp) ;
                    }else {
                        if ( tmp.a > tmp.c ) q1.push(tmp) ;
                        else q3.push(tmp) ;
                    }
                }
            } else {
                if ( q3.size() < n/2 ) q3.push(tmp) ;
                else {
                    if ( (max(q3.top().a,q3.top().b)+tmp.c) > q3.top().c+max(tmp.a,tmp.b) ) {
                        q4.push(q3.top()) ;
                        q3.pop() ;
                        q3.push(tmp) ;
                    }else {
                        if ( tmp.b > tmp.a ) q2.push(tmp) ;
                        else q1.push(tmp) ;
                    }
                }
            }
        }
        while ( q1.size() ) ans += q1.top().a , q1.pop() ;
        while ( q2.size() ) ans += q2.top().b , q2.pop() ;
        while ( q3.size() ) ans += q3.top().c , q3.pop() ;
        cout << ans << '\n' ;}
    }
    return 0 ;
}
