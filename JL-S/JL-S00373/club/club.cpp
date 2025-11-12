#include <bits/stdc++.h>
using namespace std ;
#define ll long long
ll n ;
ll a[200005][4] ;
ll cnt[4] = {0} ;
ll Ans = 0 ;
void DFS(int pos, int ans){
    if (pos == n+1){
        if (Ans < ans)
            Ans = ans ;
        //printf ("%d %d\n", Ans, ans) ;
        return ;}
    if (cnt[1] < n/2){
        cnt[1]++ ;
        //printf ("111 %d %d\n",ans, pos) ;
        DFS(pos+1, ans+a[pos][1]) ;
        cnt[1]-- ;}
    if (cnt[2] < n/2){
        cnt[2]++ ;
        //printf ("222 %d %d\n",ans, pos) ;
        DFS(pos+1, ans+a[pos][2]) ;
        cnt[2]-- ;}
    if (cnt[3] < n/2){
        cnt[3]++ ;
        //printf ("333 %d %d\n",ans, pos) ;
        DFS(pos+1, ans+a[pos][3]) ;
        cnt[3]-- ;}
}
int main (){
    ll t ;
    scanf ("%lld", &t) ;
    while(t){
        t-- ;
        scanf ("%lld", &n) ;
        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=3; j++)
                scanf ("%lld", &a[i][j]) ;
        memset(cnt, 0, sizeof(cnt)) ;
        Ans = 0 ;
        DFS(1, 0) ;
        printf("%lld\n", Ans) ;
    }
return 0 ;}
