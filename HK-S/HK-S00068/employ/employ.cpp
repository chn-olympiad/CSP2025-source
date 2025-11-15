#include <bits/stdc++.h>
using namespace std ;
#define int long long
int dp[(1<<18)][19] ;
const int MD=998244353 ;
bool comp(int a,int b){
    return __builtin_popcount(a)<__builtin_popcount(b) ;
}
void solve(){
    int N,M,i,j ;
    cin >> N >> M ;
    int A[503] ;
    string s ;
    cin >> s ;
    for (i = 0 ; i < N ; i ++) cin >> A[i] ;
    int cntt=0 ;
    for (i = 0 ; i < N ; i ++) if (s[i]=='1') cntt++ ;
    if (N<=18){
        dp[0][0]=1 ;
        vector <int> v ;
        for (i = 0 ; i < (1<<N) ; i ++) v.push_back(i) ;
        sort(v.begin(),v.end(),comp) ;
        for (int k = 0 ; k < (1<<N) ; k ++){
            int x=v[k] ;
            int y=__builtin_popcount(x) ;
            for (i = 0 ; i < N ; i ++){
                if ((1<<i)&x) continue ;
                for (j = 0 ; j <= N ; j ++){
                    if (s[y]=='1'){
                        if (A[i]>y-j){
                            if (j+1<=N) dp[x|(1<<i)][j+1]+=dp[x][j],dp[x|(1<<i)][j+1]%=MD ;
                        }
                        else dp[x|(1<<i)][j]+=dp[x][j],dp[x|(1<<i)][j]%=MD ;
                    }
                    else dp[x|(1<<i)][j]+=dp[x][j],dp[x|(1<<i)][j]%=MD ;
                }
            }
        }
        int tt=0 ;
        for (i = M ; i <= N ; i ++) tt+=dp[(1<<N)-1][i],tt%=MD ;
        cout << tt << endl ;
    }
    else if (M==N){
        for (i = 0 ; i < N ; i ++) if (s[i]=='0'){
            cout << 0 << endl ; return ;
        }
        for (i = 0 ; i < N ; i ++) if (A[i]==0){
            cout << 0 << endl ; return ;
        }
        int tt=1 ;
        for (i = 1 ; i <= N ; i ++) tt*=i,tt%=MD ;
        cout << tt << endl ;
    }
    else if (cntt==N){
        // int zcnt=0 ;
        // for (i = 1 ; i <= N ; i ++) if (A[i]==0) zcnt++ ;
        // if (N-zcnt<M) cout << 0 << endl ;
        // else {
        //     int tt=1 ;
        //     for (i = 1 ; i <= N-zcnt ; i ++) tt*=i,tt%=MD ;
        //     cout << tt << endl ;
        // }
    }
    else {

    }
}
signed main(){
    freopen("employ.in","r",stdin) ;
    freopen("employ.out","w",stdout) ;
    int T ;
    // cin >> T ;
    T=1 ;
    while (T--) solve() ;
    return 0 ;
}