#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,mod=998244353,o;
bool vis[5005];
void dfs(long long da,long long zong,long long geshu){
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(max(da,a[i]),zong+a[i],geshu+1);
            vis[i]=0;
        }
    }
    if(da*2<=zong&&geshu>=3){
        cout<<da<<' '<<zong<<endl;
        ans++;
    }
    ans%=mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        o=max(o,a[i]);
    }
    if(n==3){
    if(max(a[0],max(a[1],a[2]))*2>=a[0]+a[1]+a[2]){
    cout<<0;
    }
    else cout<<1;
    }
    else{
        dfs(0,0,0);
        cout<<ans;
    }
}
