#include<bits/stdc++.h>
using namespace std;
int a[5500];
int maxn[5500];
int sum[5500];
int n,ans=0;
void dfs(int st,int num){
    if(st>n){
        if(num>2&&sum[n]>2*maxn[n]) ans++;
        return;
    }
    maxn[st]=maxn[st-1];
    sum[st]=sum[st-1];
    dfs(st+1,num);
    maxn[st]=max(maxn[st-1],a[st]);
    sum[st]=sum[st-1]+a[st];
    dfs(st+1,num+1);
    maxn[st]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    cout<<ans%998244353;
    return 0;
}
