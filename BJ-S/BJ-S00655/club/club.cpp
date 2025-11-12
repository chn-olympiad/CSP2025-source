#include <bits/stdc++.h>
using namespace std;

int t,n,ans;
int a[100005][4];
int b[100005];
int dp[100005][4];
int vis[4];
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int x,int sum){
    if(x==n){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(vis[i]>=n/2) continue;
        else{
            vis[i]++;
            dfs(x+1,sum+a[x+1][i]);
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(vis,0,sizeof vis);
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            b[i]=a[i][1];
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(vis[j]<n/2){
                    dp[i][j]=max(dp[i][j-1],dp[i-1][n]+a[i][j]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i][j]);
                }
            }
        }
        cout<<dp[]*/
        if(a[1][2]==a[1][3] && a[1][3]==0){
            sort(b+1,b+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
            cout<<ans;
        }else{
            dfs(0,0);
            cout<<ans;
        }

    }
    return 0;
}