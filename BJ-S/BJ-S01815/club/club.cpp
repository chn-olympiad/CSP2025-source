#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int t, n, k, ans;
bool flag;
int a[N][8], dp[32][16][16];
bool vis[N];
vector<int> m;
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        m.clear();
        flag = true;
        cin>>n;
        k = n / 2, ans = 0;
        for(int i = 1; i <= n; i++){
            vis[i] = false;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            m.push_back((a[i][2] - a[i][1]));
            ans += a[i][1];
            if(a[i][3] != 0)flag = false;
        }
        if(flag){
            sort(m.begin(), m.end());
            for(int i = n - 1; i >= (n / 2); i--){
                ans += m[i];
            }
            cout<<ans<<'\n';
            continue;
        }
        if(n <= 30){
            ans = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 0; j <= min(i, k); j++){
                    for(int l = 0; l <= min(i, k); l++){
                        if(j + l > n)continue;
                        if(j > 0)dp[i][j][l] = dp[i-1][j-1][l] + a[i][1];
                        if(l > 0)dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l-1] + a[i][2]);
                        if(j + l < k)dp[i][j][l] = max(dp[i][j][l], max(dp[i-1][j-1][l], dp[i-1][j][l]) + a[i][3]);
                        else if(j + l < k - 1)dp[i][j][l] = max(dp[i][j][l], dp[i][j][l] + a[i][3]);
                        ans = max(ans, dp[i][j][l]);
                        cout<<i<<' '<<j<<' '<<l<<' '<<dp[i][j][l]<<'\n';
                    }
                    cout<<'\n';
                }
                cout<<'\n';
            }
            cout<<ans<<'\n';
            continue;
        }
    }
    return 0;
}
