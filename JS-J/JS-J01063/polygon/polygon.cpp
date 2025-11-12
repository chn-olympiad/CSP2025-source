#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v[5005],ans;
void dfs(int k,int mx,int m,long long z){
    if(k==n+1){
        if(m>=3&&z>mx*2) ans=(ans+1)%998244353;
        return;
    }
    dfs(k+1,mx,m,z);
    v[k]=1;
    dfs(k+1,max(mx,a[k]),m+1,z+a[k]);
    v[k]=0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0,(long long)0);
    cout<<ans;
    return 0;
}
