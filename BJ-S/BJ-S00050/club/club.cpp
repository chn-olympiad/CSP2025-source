#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int a[100001][3];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.first-x.second<y.first-y.second;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool f=1,f2=1;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2],f&=(a[i][1]==0&&a[i][2]==0),f2&=(a[i][2]==0);
        if(f){
            vector<int> vec(n);
            for(int i=1;i<=n;i++){
                vec[i-1]=a[i][0];
            }
            sort(vec.rbegin(),vec.rend());
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=vec[i];
            }
            cout<<ans<<'\n';
            continue;
        }
        if(f2){
            vector<pair<int,int>> vec(n);
            for(int i=1;i<=n;i++){
                vec[i-1].first=a[i][0];
                vec[i-1].second=a[i][1];
            }
            sort(vec.rbegin(),vec.rend(),cmp);
            int ans=0;
            for(int i=0;i<n/2;i++){
                ans+=vec[i].first;
            }
            for(int i=n/2;i<n;i++){
                ans+=vec[i].second;
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                for(int l=0;l<=n/2;l++){
                    dp[j][k][l]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=n/2;j>=0;j--){
                for(int k=n/2;k>=0;k--){
                    for(int l=n/2;l>=0;l--){
                        if(j>0)
                            dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][0]);
                        if(k>0)
                            dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][1]);
                        if(l>0)
                            dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][2]);
                    }
                }
            }
        }
        cout<<dp[n/2][n/2][n/2]<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
