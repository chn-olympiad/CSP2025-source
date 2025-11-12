#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int A[N],a[N][4];
int dp[35][35][35][35];
void solveA(){
    for(int i=1;i<=n;i++) A[i]=a[i][1];
    sort(A+1,A+n+1,greater<int>());
    int sum=0;
    for(int i=1;i<=n/2;i++)
        sum+=A[i];
    cout<<sum<<'\n';
}
void solve(){
    bool iA=true;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int i=1;i<=n;i++)
        iA&=(a[i][2]==0&&a[i][3]==0);
    if(iA){
        solveA();
        return ;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int s1=0;s1<=(i+1)/2;s1++)
            for(int s2=0;s2<=(i+1)/2;s2++)
                for(int s3=0;s3<=(i+1)/2;s3++){
                    if(s1+s2+s3>i) break;
                    if(s1) dp[i][s1][s2][s3]=max(dp[i][s1][s2][s3],dp[i-1][s1-1][s2][s3]+a[i][1]);
                    if(s2) dp[i][s1][s2][s3]=max(dp[i][s1][s2][s3],dp[i-1][s1][s2-1][s3]+a[i][2]);
                    if(s3) dp[i][s1][s2][s3]=max(dp[i][s1][s2][s3],dp[i-1][s1][s2][s3-1]+a[i][3]);
                    if(s1+s2+s3==n) ans=max(ans,dp[i][s1][s2][s3]);
                }
    }
    cout<<ans<<'\n';

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
