#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 20;
int T , n , a[N][4] , tot;
int f[3][110][110][110];
void solve(){
    memset(f , 0 , sizeof(f));
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i][1] >> a[i][2] >> a[i][3];
    int ans = 0;
    for(int c = 1;c <= n;c++){
        int c_ = c % 2 ;
        for(int i = 0;i <= n / 2;i++){
            for(int j = 0 ; j <= n / 2 ; j++){
                int k = c - i - j;
                if(i + j + k == c and k <= n / 2 and k >= 0){
                    if(i >= 1)f[c_][i][j][k] = max(f[c_ ^ 1][i - 1][j][k] + a[c][1] , f[c_][i][j][k]);
                    if(j >= 1)f[c_][i][j][k] = max(f[c_ ^ 1][i][j - 1][k] + a[c][2] , f[c_][i][j][k]);
                    if(k >= 1)f[c_][i][j][k] = max(f[c_ ^ 1][i][j][k - 1] + a[c][3] , f[c_][i][j][k]);
                }
                if(c == n and i + j + k == n)ans = max(ans , f[c_][i][j][k]);
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        solve();
    }





    return 0;
}
