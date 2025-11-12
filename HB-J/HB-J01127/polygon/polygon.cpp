#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
long long ans;
void dfs(int wz,int bs,int maxx,long long len){
    if(bs>=3&&len>maxx*2){
        ans=(ans+1)%998244353;
    }
    for(int i=wz+1;i<=n;i++){
        dfs(i,bs+1,max(maxx,a[i]),len+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++){
        dfs(i,1,a[i],a[i]);
    }
    cout<<ans;
    return 0;
}
