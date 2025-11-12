#include<bits/stdc++.h>
using namespace std;
int n,a[100007][4],t,c[4] = {0,0,0,0},ans,k,p;
int dfs(int s,int sum){
    if(s == n){
        ans = max(ans,sum);
        return 0;
    }
    for(int i = 1;i <= 3;i++){
        if(c[i] == n / 2){
            continue;
        }
        c[i]++;
        dfs(s + 1,sum + a[s + 1][i]);
        c[i]--;
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans = -1;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(0,0);
        cout << ans << "\n";
    }
    return 0;
}

