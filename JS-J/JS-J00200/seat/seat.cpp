//我真的服了这个code block
//欸似乎不建立project也可以运行欸
//之前唐了
//9.01ACT2
#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
using namespace std ;
const ll MAXN = 105 ;
ll n , m , i , j , p , x = 1 , y = 1 , d = 1 , a[MAXN] , s[15][15] ;
int main(){
    freopen("seat.in","r",stdin) ;
    freopen("seat.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m ;
    for(i=1;i<=n*m;i++){
        cin >> a[i] ;
    }
    p = a[1] ;
    sort(a+1,a+1+n*m,greater<ll>()) ;
    for(i=1;i<=n*m;i++){
        s[x][y] = a[i] ;
        if(a[i]==p){
            cout << x << " " << y ;
            return 0 ;
        }
        y += d ;
        if(y<1){
            x++ ;
            y = 1 ;
            d = -d ;
        }else {
            if(y>m){
                x++ ;
                y = m ;
                d = -d ;
            }
        }
    }
    return 0 ;
}
