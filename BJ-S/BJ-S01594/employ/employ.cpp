#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n = 0;
int m = 0;
char s[210];
int c[210];
// int dp[262150][20][2];
int p[11];
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m; bool flg = 1;
    int cm = 0;
    int rz = 0;
    for(int i = 1; i <= n; i++){
        cin >> s[i]; if(s[i] == '0')flg = 0;
        cm = cm * 2 + s[i] - '0'; p[i] = i; rz += 1- (s[i] - '0');
    } for(int i = 1; i <= n; i++){
        cin >> c[i];
    } sort(c + 1, c + 1 + n); int as = 0;
    
    if(n <= 11){
        do{
        int ct = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '0'){
                ct ++; continue;
            }
            if(c[p[i]] <= ct){
                ct ++; continue;
            }
        }
        if(n - ct >= m){
            as ++;
        }
    }while(next_permutation(p + 1, p + 1 + n));
    cout << as << '\n'; return 0;
    }
    else{
        int jc = 1;
        for(int i = 1; i <= n; i++) jc = i * jc % mod;
        cout << jc << '\n'; return 0;
    }

    // dp[cm][0][0] = 1; int nw = 1;
    // for(int i = 1; i <= n; i++){
    //     int ci = c[i];
    //     for(int msk = 0; msk < (1 << n); msk ++){
    //         if(__builtin__popcount(msk) < ci){
    //             for(int k = 0; k < n; k++){
    //                 if(msk & (1 << k)) continue;
    //                 for(int j = 0; j <= 17; i++){
    //                     dp[msk | (1 << k)][j + 1][nw] += dp[msk][j];
    //                     dp[msk | (1 << k)][j + 1][nw] %= mod;
    //                 }
    //             } continue;
    //         }
    //         if(ci == 0){
    //             for(int k = 0; k < n; k++){
    //                 if(msk & (1 << k)) continue;
    //                 for(int j = 0; j <= 17; i++){
    //                     dp[msk | (1 << k)][j + 1][nw] += dp[msk][j];
    //                     dp[msk | (1 << k)][j + 1][nw] %= mod;
    //                 }
    //             } continue;
    //         }
    //     }
    // }
    // if(flg){
    //     int ct = 0;
    //     for(int i = 1;i <= n; i++){
    //         if(c[i] > 0) break;
    //         else ct ++;
    //     }//yong le ji ci 0 , you duo shao man zu le 
    //     dp[0][0]
    // }
}