#include <bits/stdc++.h>
using namespace std;
int n, ans;
int visx[5];
int mp[5][100010];
void dfs(int m, int sum){
    if(m>n){
        ans=max(ans, sum);
        return ;
    }
    for(int i = 1;i <= 3;i++){
        if(visx[i]<n/2){
            visx[i]++;
            dfs(m+1, sum+mp[i][m]);
            visx[i]--;
        }
    }
}
void solve(){
    visx[1]=visx[2]=visx[3]=0;
    ans=0;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> mp[1][i] >> mp[2][i] >> mp[3][i];
    dfs(1, 0);
    cout << ans << "\n";
}
int _;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}
