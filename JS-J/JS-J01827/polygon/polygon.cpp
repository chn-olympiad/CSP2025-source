#include<bits/stdc++.h>
using namespace std;
int n,a[10010];
long long ans=0;
void dfs(int i,int s,int maxx,int sum){
    if(s>=3){
        if(sum>maxx*2){
            ans++;
            ans=ans%998244353;
        }
    }
    if(i==n+1){
        return;
    }
    if(a[i]>maxx) dfs(i+1,s+1,a[i],sum+a[i]);
    else dfs(i+1,s+1,maxx,sum+a[i]);
    if(i==n+1){
        return;
    }
    dfs(i+1,s,maxx,sum);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans-2;
    return 0;
}
