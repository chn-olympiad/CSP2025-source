#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[205][105][105];
ll a[100005][4];
ll b[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n;
        bool flag1=1,flag2=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][3]!=0){
                flag1=0;
                flag2=0;
            }
            if(a[i][2]!=0){
                flag1=0;
            }
        }
        ll ans=0;
        //dp[1][0][0]=a[1][1];
        //dp[0][1][0]=a[1][2];
        //dp[0][0][1]=a[1][3];
        //cout<<"manba out\n";
        memset(dp,0,sizeof(dp));
        if(flag1){
            //cout<<"flag1:\n";
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1,greater<int>());
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
            cout<<ans;
            continue;
        }
        if(flag2){
            //cout<<"flag2:\n";
            for(int i=1;i<=n;i++){
                for(int j=min(n/2,i);j>=0;j--){
                    int k=i-j;
                    if(k>n/2) continue;
                    if(j){
                        dp[j][k][0]=max(dp[j-1][k][0]+a[i][1],dp[j][k][0]);
                    }if(k){
                        dp[j][k][0]=max(dp[j][k-1][0]+a[i][2],dp[j][k][0]);
                    }
                    ans=max(ans,dp[j][k][0]);
                    //cout<<"i,j,k,l,dp:"<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[j][k][l]<<endl;
                }
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=min(n/2,i);j>=0;j--){
                for(int k=min(n/2,i-j);k>=0;k--){
                    int l=i-j-k;
                    if(l>n/2) continue;
                    if(j){
                        dp[j][k][l]=max(dp[j-1][k][l]+a[i][1],dp[j][k][l]);
                    }if(k){
                        dp[j][k][l]=max(dp[j][k-1][l]+a[i][2],dp[j][k][l]);
                    }if(l){
                        dp[j][k][l]=max(dp[j][k][l-1]+a[i][3],dp[j][k][l]);
                    }

                    ans=max(ans,dp[j][k][l]);
                    //cout<<"i,j,k,l,dp:"<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[j][k][l]<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
