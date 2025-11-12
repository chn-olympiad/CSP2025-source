#include <bits/stdc++.h>
using namespace std;
int n,a[505],dp[502][102][502],ans=0;
int dfs(int x,int y,int k){
    if(k==0){
        if(y<=0){
           return 1;
        }
        return 0;
    }
    if(x==0){
        return 0;
    }
    if(y<0){
        y=0;
    }
    if(dp[x][y][k]!=-1){
        return dp[x][y][k];
    }
    int g=0;
    for(int i=0;i<x;i++){
        g=(g+dfs(i,y-a[i],k-1))%998244353;
    }
    dp[x][y][k]=g;
    return dp[x][y][k];
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        for(int j=i-1;j<n;j++){
            ans+=dfs(j,a[j]+1,i-1);
            ans%=998244353;
        }
    }
    cout<<ans;
    return 0;
}
