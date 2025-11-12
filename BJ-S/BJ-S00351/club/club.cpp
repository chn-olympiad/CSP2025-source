#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][5];
int ans;
int n;
void dfs(int depth,int sa,int sb,int sc,int sum){
    if(depth > n){
        ans = max(ans,sum);
        return;
    }
    if(sa)dfs(depth+1,sa-1,sb,sc,sum+a[depth][1]);
    if(sb)dfs(depth+1,sa,sb-1,sc,sum+a[depth][2]);
    if(sc)dfs(depth+1,sa,sb,sc-1,sum+a[depth][3]);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(1,n/2,n/2,n/2,0);
        cout << ans << '\n';
    }
    return 0;
}
