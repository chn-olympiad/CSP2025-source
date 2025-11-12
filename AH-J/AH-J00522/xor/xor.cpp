#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
int dp[500010];
int n,k;
int ans;
void dfs(int m,int cnt,int sum,int t){
    if(m>n){
        if(sum==k&&t!=0)cnt++;
        ans=max(ans,cnt);
        return;
    }if(sum==k&&t!=0){
        dfs(m+1,cnt+1,a[m],1);
        dfs(m+1,cnt+1,0,0);
    }dfs(m+1,cnt,sum^a[m],t+1);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }if(n<=20)dfs(1,0,0,0);
    else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j]^s[i-1]==k){
                    dp[j]=max(dp[j],dp[i-1]+1);
                }
            }ans=max(ans,dp[n]);
        }
    }cout<<ans;
    return 0;
}
