#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5005],maxa=-1,dp[5005][5005],kkk;
int c(){
    for(int i=1;i<=n;i++)dp[i][1]=i,dp[i][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=2;j<i;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
}
void work(){
    c();
    int ans=0;
    for(int i=3;i<=n;i++)ans=(ans+dp[n][i])%mod;
    cout<<ans;
}
int dfs(int start,int len,int longest,int numm){
    if(numm>=3&&len>2*longest)kkk=(kkk+1)%mod;
    for(int i=start+1;i<=n;i++)
        dfs(i,len+a[i],max(longest,a[i]),numm+1);
    return kkk;
}
int main(){
    freopen("polygon4.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];maxa=max(maxa,a[i]);}
    if(n==3)cout<<((a[3]+a[1]>a[2]&&a[3]+a[2]>a[1]&&a[2]+a[1]>a[3])?1:0);
    if(maxa==1)work();
    else cout<<dfs(0,0,0,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
