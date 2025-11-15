#include <bits/stdc++.h>
using namespace std ;
#define int long long
int A[100003][3] ;
bool comp(pair<int,int>a,pair<int,int>b){
    return a.first-a.second<b.first-b.second ;
}
void solve(){
    int N,i,j ;
    vector <pair<int,int>> v[3] ;
    scanf("%lld",&N) ;
    for (i = 1 ; i <= N ; i ++) for (j = 0 ; j < 3 ; j ++) scanf("%lld",&A[i][j]) ;
    int tt=0 ;
    for (i = 1 ; i <= N ; i ++){
        int mx=-1 ;
        for (j = 0 ; j < 3 ; j ++){
            mx=max(mx,A[i][j]) ;
        }
        tt+=mx ;
        for (j = 0 ; j < 3 ; j ++){
            if (mx==A[i][j]){
                v[j].push_back({A[i][j],A[i][0]+A[i][1]+A[i][2]-A[i][j]-min(A[i][0],min(A[i][1],A[i][2]))}) ;
                break ;
            }
        }
    }
    for (i = 0 ; i < 3 ; i ++){
        if ((int)v[i].size()>N/2){
            sort(v[i].begin(),v[i].end(),comp) ;
            for (j = 0 ; j < (int)v[i].size()-N/2 ; j ++){
                tt-=v[i][j].first ;
                tt+=v[i][j].second ;
            }
        }
    }
    printf("%lld\n",tt) ;
}
signed main(){
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    int T ;
    cin >> T ;
    while (T--) solve() ;
    return 0 ;
}