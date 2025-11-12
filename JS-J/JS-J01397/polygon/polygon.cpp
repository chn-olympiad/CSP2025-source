#include <bits/stdc++.h>
#define ll long long
using namespace std ;
long long  a[1000001] ;
long long ans = 0 , n ;
inline void dfs(ll len , ll x ,long long sum,ll t,long long mx){//chose num,the xth ,the number of ,max
    if(t == len){
        if(sum > mx*2){
            ans++ ;
        }
        return ;
    }

    for(int i = x; i <= n; i++){
       int mx1 = max(a[i],mx) ;
       //mx = max(mx,a[i]) ;
        dfs(len,i+1,sum + a[i],t+1,mx1) ;
    }
}
int main(){
    freopen("polygon.in","r",stdin) ;
    freopen("polygon.out","w",stdout) ;
    scanf("%lld",&n) ;
    for(ll i = 1; i <= n; i++){
        scanf("%lld",&a[i]) ;
    }
    //sort(a+1,a+n+1) ;
    for(ll len = 3; len <= n; len++){
        dfs(len,1,0,0,0) ;
    }
    printf("%lld",ans % 998244353) ;
    return 0 ;
}
