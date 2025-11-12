#include <bits/stdc++.h>
using namespace std;
long long ans,a[100005],n;
void dfs(long long i,long long sum,long long ma,long long m){
    if(i==n+1){
        if(sum>=3&&2*ma<m){
            ans++;
            ans=ans%998244353;
        }
        return ;
    }
    dfs(i+1,sum+1,max(ma,a[i]),m+a[i]);
    dfs(i+1,sum,ma,m);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
