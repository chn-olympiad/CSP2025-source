#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,ans;
void dfs(int dep,int sum,int mx,int k){
    if(dep>n){
        if(k>=3&&sum>mx*2)ans++;
        return ;
    }
    dfs(dep+1,sum+a[dep],max(mx,a[dep]),k+1);
    dfs(dep+1,sum,mx,k);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(mx==1){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=998244353;
        }
        ans-=1+n+n*(n-1)/2;
        if(ans<0)ans+=998244353;
        cout<<ans;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}