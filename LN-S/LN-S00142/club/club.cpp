/*
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200010][4];
int ans;
void dfs(int pos,int num1,int num2,int num3,int cnt){
    if(num1 > n/2 || num2 > n/2 || num3 > n/2) return;
    if(pos == n+1){
        ans = max(ans,cnt);
        return;
    }
    dfs(pos+1,num1+1,num2,num3,cnt+a[pos][1]);
    dfs(pos+1,num1,num2+1,num3,cnt+a[pos][2]);
    dfs(pos+1,num1,num2,num3+1,cnt+a[pos][3]);
}
int tmp[200020];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans = -1;
        int check = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=3;j++){
                cin>>a[i][j];
                if(j != 1) check += a[i][j];
            }
        }
        if(check != 0){
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
        else{
            for(int i = 1;i<=n;i++) tmp[i] = a[i][1];
            sort(tmp+1,tmp+1+n,cmp);
            ans = 0;
            for(int i = 1;i<=n/2;i++) ans += tmp[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200010][4];
int dp[201][201][201];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                for(int k = 0;k<=n;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        //cout<<t<<"___________________________"<<endl;
        int ans = -1;
        dp[0][0][0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=i;j++){
                for(int k = 0;k<=i;k++){
                    if(i - j - k > n/2 || j > n/2 || k > n/2) continue;
                    if(j-1 >= 0 && i+1-j-k<=n/2) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                    if(k-1 >= 0 && i+1-j-k<=n/2) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                    if(i-j-k>=0 && i+1-j-k<=n/2) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
                    ans = max(ans,dp[i][j][k]);
                    //cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
