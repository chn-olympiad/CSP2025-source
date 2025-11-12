#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[5005];
const int mod=998244353;
void dfs(int x,int maxx,int st,int bi){
    if(x>2*maxx&&bi>=3){
        ans=(ans+1)%mod;
        return;
    }
    if(st>n){
        return;
    }
    if(a[st]>maxx){
        dfs(x+a[st],a[st],st+1,bi+1);
        dfs(x,maxx,st+1,bi);
    }
    else{
        dfs(x+a[st],maxx,st+1,bi+1);
        dfs(x,maxx,st+1,bi);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,INT_MIN,1,0);
    cout<<ans;
    return 0;
}
