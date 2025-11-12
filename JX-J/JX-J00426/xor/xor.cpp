#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[15000];
int dp[15000][15000];
int ans[15000][15000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int t=0;t<n;t++){
        for(int i=1,j=i+t;j<=n;i++,j++){
            if(i==j){
                if(a[i]==k){
                    dp[i][j]=1;
                    ans[i][j]=a[i];
                }
                else{
                    dp[i][j]=0;
                    ans[i][j]=a[i];
                }
            }
            else{
                for(int o=i;o<j;o++){
                    dp[i][j]=max(dp[i][j],dp[i][o]+dp[o+1][j]);
                }
                if(ans[i][j-1]^a[j]==k){
                        dp[i][j]=max(dp[i][j],1);
                }
            }
            ans[i][j]=a[i];
            for(int y=i+1;y<=j;y++)ans[i][j]^=a[y];
        }
    }
    cout<<dp[1][n];
    return 0;

}
