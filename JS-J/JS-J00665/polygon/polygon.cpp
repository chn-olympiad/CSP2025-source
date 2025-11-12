#include<bits/stdc++.h>
using namespace std;
int arr[5005],n=0;
int dp[5005][5005];
const int MOD=998244353;
int cnt(int t1,int t2){
    int ans=0;
    for(int i = t1-1;i<t2;i++){
        int sum1=0;
        for(int j = i;j>=i-t1+1;j--){
            sum1+=arr[j];
        }
        if(sum1>2*arr[t2])ans++;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    int maxx=0;
    sort(arr+1,arr+n+1);
    for(int i = 3;i<=n;i++){
        for(int j = 3;j<=n;j++){
            dp[i][j]=(max(dp[i-1][j-1],dp[i-1][j])+cnt(i,j))%MOD;
        }
    }
    for(int i = 3;i<=n;i++){
        maxx=max(maxx,dp[i][n]);
    }
    cout<<maxx;
    return 0;
}
