#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int x,y,z;
}a[100001];
namespace solve1{
    int dp[211][201][201];
    void work(){
        memset(dp,128,sizeof(dp));
        dp[0][0][0]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2&&j<=i;j++){
                for(int k=0;k<=n/2&&j+k<=i;k++){
                    if(i-j-k>n/2){
                        continue;
                    }
                    if(dp[i-1][j][k]>=0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].z);
                    }
                    if(j>=1&&dp[i-1][j-1][k]>=0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
                    }
                    if(k>=1&&dp[i-1][j][k-1]>=0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
                    }
                    if(i==n){
                        ans=max(ans,dp[i][j][k]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
namespace solve2{
    bool cmp(node x,node y){
        return x.x>y.x;
    }
    void work(){
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++){
            ans+=a[i].x;
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool ok=true;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y!=0||a[i].z!=0){
                ok=false;
            }
        }
        if(ok){
            solve2::work();
        }else{
            solve1::work();
        }
    }
}
