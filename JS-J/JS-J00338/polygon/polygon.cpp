#include <bits/stdc++.h>
using namespace std;
int aans,n,a[5005],dp[2][25000100];
int qzh[10005],maxx[10005];
void dg(int dep,int s,int mmax){
    if(dep>n){
        if(mmax*2<s)aans++;
        return ;
    }
    else{
        dg(dep+1,s+a[dep],max(mmax,a[dep]));
        dg(dep+1,s,mmax);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=20){
        dg(1,0,0);
        cout<<aans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    dp[0][a[1]+a[2]]++;
    dp[0][a[3]+a[2]]++;
    dp[0][a[1]+a[3]]++;
    dp[0][a[3]]++;
    dp[0][a[1]]++;
    dp[0][a[2]]++;
    dp[0][a[1]+a[2]+a[3]]++;
    for(int i=3;i<=n;i++){
        for(int j=qzh[i-1];j>=0;j--){
            if(a[i]*2<j+a[i])dp[1][j+a[i]]+=dp[0][j]+dp[1][j];
            if(a[i]*2>=j+a[i]&&i!=3)dp[0][j+a[i]]+=dp[0][j]+dp[1][j];
        }
    }
    int ans=0;
    for(int j=1;j<=qzh[n];j++){
        ans+=dp[1][j];
    }
    cout<<ans;
    return 0;
}