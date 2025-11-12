//T4想出来了一种奇怪解法
//不知道能拿多少分
//估计60～70分吧
#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
using namespace std ;
const ll MAXN = 5005 , mod = 998244353 ;
ll n , i , cnt , a[MAXN] ;
void dfs(ll dep , ll sum , ll maxx , ll num){
    if(dep>n){
        if(sum>maxx*2 && num>=3){
            cnt++ ;
        }
        return ;
    }
    dfs(dep+1,sum+a[dep],max(maxx,a[dep]),num+1) ;
    dfs(dep+1,sum,maxx,num) ;
}
int main(){
    freopen("polygon.in","r",stdin) ;
    freopen("polygon.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n ;
    for(i=1;i<=n;i++){
        cin >> a[i] ;
    }
    dfs(1,0,0,0) ;
    cout << cnt ;
    return 0 ;
}
