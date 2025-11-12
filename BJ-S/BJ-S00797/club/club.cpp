#include<bits/stdc++.h>
using namespace std;
const int N = 2e5,M = 1e4;
struct satisfaction{
    int a1,a2,a3;
}sat[N];
bool cmp(satisfaction a,satisfaction b){
    return a.a1 > b.a1;
}
int dp[M][M];
int main(){
    freopen("club.in","r",stdin);
    freoepn("club.out","w",stdout);
    int t;
    cin >> t;
    while(t --){
        int n;
        bool flagA = true,flagB = true;
        cin >> n;
        for(int i = 0;i < n;i ++){
            cin >> sat[i].a1 >> sat[i].a2 >> sat[i].a3;
            if(sat[i].a2 != 0 || sat[i].a3 != 0) flagA = false;
            if(sat[i].a3 != 0) flagB = false;
        }
        if(flagA){
            int ans = 0;
            sort(sat,sat + n,cmp);
            for(int i = 0;i < n / 2;i ++) ans += sat[i].a1;
            cout << ans << "\n";
            continue;
        }
        if(n == 2){
            int ans1 = sat[0].a1 + max(sat[1].a2,sat[1].a3);
            int ans2 = sat[0].a2 + max(sat[1].a1,sat[1].a3);
            int ans3 = sat[0].a3 + max(sat[1].a1,sat[1].a2);
            cout << max(ans1,max(ans2,ans3));
        }
        dp[0][0] = 0;
        if(flagB){
            int ans = 0;
            for(int j = 1;j <= (n / 2);j ++){
                for(int k = 1;k <= (n / 2);k ++){
                   for(int i = 0;i < n;i ++){
                        dp[j][k] = max(dp[j - 1][k] + sat[i].a1,dp[j][k - 1] + sat[i].a2);
                        cout << dp[j][k] << " " << i << " " << j << " " << k << "\n";

                    }
                }
            }
            cout << dp[n / 2][n / 2] << "\n";
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
