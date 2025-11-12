#include<bits/stdc++.h>
using namespace std;
int n;
int a[60005],dp[60005];
long long maxa=-1;
long long ans=0,sum=0;
void dfs(int x,int k,int l){
     if(x==l){
        sum=0;maxa=-1;
        for(int i=1;i<=n;i++){
            if(dp[i]==1){
                sum=sum+a[i];
            if(a[i]>maxa){
                maxa=a[i];
                }
            }
        }
        if(maxa*2<sum){
            ans++;
        }
        return;
     }
     for(int i=k;i<=n;i++){
        if(dp[i]!=1){
           dp[i]=1;
           dfs(x+1,i+1,l);
           dp[i]=0;
        }
     }
}
void dfs111(int x,int k,int l){
     if(x==l){
        ans++;
        return;
     }
     for(int i=k;i<=n;i++){
        if(dp[i]!=1){
           dp[i]=1;
           dfs(x+1,i+1,l);
           dp[i]=0;
        }
     }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
          p++;
        }
    }
    if(p==n){
        for(int i=3;i<=n;i++){
            dfs111(0,1,i);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        dfs(0,1,i);
        for(int i=1;i<=n;i++){
            dp[i]==0;
        }
    }
    cout<<ans%998244353;
    return 0;
}
