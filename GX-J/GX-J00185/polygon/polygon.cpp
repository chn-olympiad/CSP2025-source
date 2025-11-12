#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5007,mod=998244353;
ll n,a[N],ans;
void dfs(ll t,ll sum,ll maxv,ll ge){
    if(t==n+1){
        if(sum>maxv*2&&ge>=3){ans++;ans=ans%mod;}
        return;
    }
    dfs(t+1,sum+a[t],max(maxv,a[t]),ge+1);
    dfs(t+1,sum,maxv,ge);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans%mod<<endl;
    return 0;
}
