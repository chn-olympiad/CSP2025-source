#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0;
void dfs(long long h,long long m){
    if(h>m){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        dfs(h+a[i],max(m,a[i]));
        dfs(h,m);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0);
    cout<<ans%998244353;
    return 0;
}
