#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,a[N][4],ans,sum[4];

void dfs(int now,int num){
    if(now==n+1){
        ans=max(ans,num);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(sum[i]<n/2){
            sum[i]++;
            dfs(now+1,num+a[now][i]);
            sum[i]--;
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)cin>>a[i][j];
    }
    dfs(1,0);
    cout<<ans<<'\n';
    ans=0;
    for(int i=1;i<=3;i++)sum[i]=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
