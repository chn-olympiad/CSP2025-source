#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],cnt,v,mod=998244353;
void dfs(int x,long long maxn,long long num){
    if(x>3&&num>maxn*2){
        cnt++;
    }
    if(x==n+1){
        return;
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        vis[i]=1;
        dfs(x+1,max(maxn,a[i]),num+a[i]);
        vis[i]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)v=1;
    }
    if(v==0){
        cnt=1;
        for(int i=1;i<=n;i++){
            cnt*=2;
            cnt%=mod;
        }
        cnt+=(mod-n-(n*(n-1)/2));
        cnt%=mod;
    }else{ 
        dfs(1,0ll,0ll);
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}