#include "bits/stdc++.h"
#define int long long
using namespace std;
int a[5005],n,sum[5005];
int mod=998244353,cnt,k=n;
void dfs(int t,int sum,int maxn){
    if(t==n+1){
        if(sum>maxn*2){
            cnt++;
            cnt%=mod;
            k--;
        }
        return ;
    }
    dfs(t+1,sum+a[t],a[t]);
    dfs(t+1,sum,maxn);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<cnt%mod;
    return 0;
}

