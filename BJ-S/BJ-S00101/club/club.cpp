#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[205][205][205];
int t,n;
int a[N][3];
int b[N];
bool q=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        q=1;
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            b[i]=a[i][0];
            if(a[i][1]!=0||a[i][2]!=0)q=0;
        }
        if(q){
            sort(b+1,b+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
            cout<<ans<<endl;
        }else{
            for(int l=0;l<=n;l++){
                for(int i=l;i>=0;i--){
                    for(int j=l-i;j>=0;j--){
                        int k=l-i-j;
                        if(i+1<=n/2)dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[l+1][0]);
                        if(j+1<=n/2)dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[l+1][1]);
                        if(k+1<=n/2)dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a[l+1][2]);
                    }
                }
            }
            int ans=0;
            for(int i=0;i<=n/2;i++){
                for(int j=0;j<=n/2;j++){
                    if(n-i-j>n/2)continue;
                    ans=max(ans,dp[i][j][n-i-j]);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}