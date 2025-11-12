#include<bits/stdc++.h>
using namespace std;
int n, t, r, ans;
int a[100010][10], dp[100010][10];
bool pan[100010][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int z = 1;z <= t;z++){
        cin >> n;
        r = n/2;
         for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j];
                dp[i][j] = 0;
            }
         }
         for(int j = 1;j <= 3;j++){
            for(int i = 1;i <= n;i++){
                for(int y = r;y >= 1;y--){
                    if(dp[y-1][j] + a[i][j] > dp[y][j]){
                        if(j == 1){
                            a[i][2] = a[i][3] = 0;
                        }else if(j == 2){
                            a[i][3] = 0;
                        }
                    }
                    dp[y][j] = max(dp[y][j], dp[y-1][j] + a[i][j]);
                }
            }
         }
         for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
         }
         //cout << endl;
         cout << dp[r][1] + dp[r][2] + dp[r][3] << endl;
    }
    return 0;
}
