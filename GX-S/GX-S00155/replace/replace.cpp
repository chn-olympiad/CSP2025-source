#include<bits/stdc++.h>
using namespace std ;

#define int long long

const int base = 13331 , mod = 998244353 , N = 2e5 + 5 ;

int n , q ; 

string s[N] , t[N] ;

int ls[N] , cnt , H[N] ;

int a[N][2] ; 

int Pow(int x,int n) {
    if(n == 0) return 1 ;
    int a = Pow(x,n/2) ;
    return  a * a % mod * (n & 1 ? x : 1 ) % mod ;
}

// 2e5 * 2e5 / 8 

int ls2[N] , ls3[N] ;

int cnt1, cnt2 ; 

int ans[N] ;

bool ok1[N] , ok2[N] ;

vector<int> ggg[N] ;

signed main() {
    freopen("replace.in","r",stdin) ;
    freopen("replace.out","w",stdout) ;
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> s[i] >> t[i] ; 
        if( s[i ] == t[i]) continue ;
        int len = s[i].size() ;
        int frp = 0 ; 
        while(frp < s[i].size() && s[i][frp] == t[i][frp] )frp ++ ;
        int edp = 0 ;
        while(edp < s[i].size() && s[i][len-edp-1] == t[i][len-edp-1] ) edp ++ ;
        edp = len - edp ;
         edp -- ; 
        int h1=0,h2 =0 ;    
        int z = 0  , w = 0 ;
        for(int j = frp - 1 ; j >= 0 ; j -- ) z = (z * base % mod + s[i][j] ) % mod ;
        for(int j = edp + 1 ; j < len ; j ++ ) w = (w * base % mod + s[i][j] ) % mod ;
        for(int j = frp ; j <= edp ; j ++ ) {
            h1 = (h1 * base % mod + s[i][j] ) % mod ;
            h2 = (h2 * base % mod + t[i][j] ) % mod ;
            // cout << s[i][j] << ' ' << t[i][j] << '\n' ;
        } h1 = (h1 * Pow(base,edp-frp+1) % mod + h2 ) % mod ;
        // cout << h1 << '\n' ;
        ls[++cnt] = h1 ; H[i] = h1 ;
        a[i][0] = z ; a[i][1] = w ;
        ls2[++cnt1] = z ; ls3[++cnt2] = w ;
    }sort(ls+1,ls+1+cnt) ; 
    cnt = unique(ls+1,ls+1+cnt) - ls - 1 ;
    sort(ls2+1,ls2+1+cnt1) ; 
    sort(ls3+1,ls3+1+cnt2) ; 
    cnt1 = unique(ls2+1,ls2+1+cnt1) - ls2 - 1 ;
    cnt2 = unique(ls3+1,ls3+1+cnt2) - ls3 - 1 ; 
    for(int i = 1 ; i <= n ; i ++ ) {
        H[i] = lower_bound(ls+1,ls+1+cnt,H[i]) - ls ;
        ggg[H[i]].push_back(i) ;
        a[i][0] = lower_bound(ls2+1,ls2+1+cnt1,a[i][0] ) - ls2 ; 
        a[i][1] = lower_bound(ls3+1,ls3+1+cnt2,a[i][1]) - ls3  ;      
    }
    for(int i = 1 ; i <= q ; i ++ ) {
        string s , t ;
        cin >> s >> t ;  
        if(s.size() != t.size() ) {
            cout << 0 << '\n' ;continue ;
        }
        int frp = 0 ; 
        while(frp < s.size() && s[frp] == t[frp] )frp ++ ;
        int edp = 0 ;
        int len = s.size() ;
        while(edp < s.size() && s[len-edp-1] == t[len-edp-1] ) edp ++ ;
        // edp == 1 
        edp = len - edp ;
         edp -- ; 
        int h1=0,h2 =0 ;    
        for(int j = frp ; j <= edp ; j ++ ) {
            h1 = (h1 * base % mod + s[j] ) % mod ;
            h2 = (h2 * base % mod + t[j] ) % mod ;
        } h1 = (h1 * Pow(base,edp-frp+1) % mod + h2 ) % mod ;
        int pos = lower_bound(ls+1,ls+1+cnt,h1) - ls ;
        if(pos >cnt || ls[pos] != h1 ) {
            cout << 0 << '\n' ; continue ;
        }
        int nw = 0 ;

        for(int j = 1 ; j <= cnt2 ; j ++ ) ok2[j] = 0 ;
        for(int j = 1 ; j <= cnt1 ; j ++ ) ok1[j] = 0 ;

        for(int j = frp  ; j >= 0 ; j --  ) {            
            int pos = lower_bound(ls2+1,ls2+1+cnt1,nw) - ls2 ; 
            if(pos > cnt1 || ls2[pos] != nw ) {}
            else {
                ok1[pos] = 1 ;
            }
            if(j)nw = (nw * base % mod + s[j-1] ) % mod ;
        }   
         nw = 0 ;
        for(int j = edp ; j < len ; j ++ ) {    
            int pos = lower_bound(ls3+1,ls3+1+cnt2,nw) - ls3 ; 
            if( pos > cnt2 || ls3[pos] != nw ) {}
            else {
                ok2[pos] = 1 ; 
            }
            if(j < len - 1 ) nw = (nw * base % mod + s[j+1] ) % mod ; 
        }int ans =0  ;
        for(int x : ggg[pos]) if( ok1[a[x][0]] && ok2[a[x][1]] ) ans ++ ;
        cout << ans << '\n' ;
    }
    return 0 ;
}