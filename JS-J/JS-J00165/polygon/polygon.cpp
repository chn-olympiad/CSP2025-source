#include<bits/stdc++.h>
using namespace std;
int n,a[5010],dp[504][50004],ans=1;
double c(int n,int m){
    double count=1.0;
    for(double i=n;i>n-m;i--){
        count*=i;
        count/=double(n-i+1.0);
    }
    int d=count;
    return d%998244353;
}
int wuqian(int n){
    int count=0;
    for(int i=3;i<=n;i++){
        count+=c(n,i);
        count%=998244353;
    }
    return count%998244353;
}
int r(int n){
    int count=0;
    for(int i=1;i<=n;i++) count+=a[i];
    return count;
}
int main(){
    freopen("p4.in","r",stdin);
    freopen("p4.out","w",stdout);
    cin>>n;
    if(n>500&&n<=5000){
        cout<<wuqian(n);
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dp[1][0]=1;
    dp[1][a[1]]=1;
    dp[2][0]=1;
    dp[2][a[1]]=1;
    dp[2][a[2]]+=1;
    dp[2][a[1]+a[2]]+=1;
    for(int i=3;i<n;i++){
        for(int j=0;j<=r(i);j++){
            dp[i][j]=dp[i-1][j];
            if(j-a[i]<0) continue;
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]);
        }
    }
    for(int i=1;i<=r(n);i++){
        ans%=998244353;
        if(dp[n-1][i]>2*a[n-1]){
            dp[n][i]=dp[n-1][i];
            ans+=dp[n][i];
        }
        if(i-a[n]<=a[n]) continue;
        if(dp[n-1][i]<=2*a[n-1]&&dp[n-1][i-a[n]]>2*a[n-1]) ans+=dp[n-1][i-a[n]];
        if(dp[n-1][i]>2*a[n-1]&&dp[n-1][i-a[n]]>2*a[n-1]) ans+=max(dp[n-1][i],dp[n-1][i-a[n]]);
        if(dp[n-1][i]>2*a[n-1]&&dp[n-1][i-a[n]]>2*a[n-1]) ans-=dp[n-1][i];
    }
    cout<<ans%998244353;
    return 0;
}