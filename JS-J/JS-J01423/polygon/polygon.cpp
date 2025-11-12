#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005],ans=0;
void dfs(int dep,int sum,int maxx,int cnt){
    if(dep>n){
        if(sum>2*maxx&&cnt>=3)ans=(ans+1)%mod;
        return;
    }
    if(n-dep+1<3-cnt)return;
    if(n-dep+1>3-cnt)dfs(dep+1,sum,maxx,cnt);
    dfs(dep+1,sum+a[dep],a[dep],cnt+1);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    cout<<ans%mod;
    return 0;
}//2^n, 40pts
