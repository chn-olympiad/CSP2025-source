#include<bits/stdc++.h>
#define itn int
#define fro for
#define elif else if
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
const ll mod=998244353;
ll n;
ll ans,a[10000007];
ll vis[10000007];
void dfs(ll u,ll mx,ll sum,ll sct){
    if(u>n){
        if(sct>=3&&sum>mx*2){ans++;ans%=mod;}
        return;
    }
    dfs(u+1,max(mx,a[u]),sum+a[u],sct+1);
    dfs(u+1,mx,sum,sct);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,0);
    cout<<ans%mod;
    return 0;
}
/*
1 2 3 4 5
1 3 6 10 15
2 4 6 8 10
0 0 0 2

*/
