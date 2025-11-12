#include <bits/stdc++.h>
using namespace std;
int a[1234567][3], vis[888], ans, n;
void dfs(int x, int sum){
    if (x>n){
        ans = max(ans,sum);
        return;
    }
    for (int i = 0;i<3;i++){
        if (vis[i]*2<n){
            vis[i]++;
            dfs(x+1,sum+a[x][i]);
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        for (int i = 1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
