#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],ans;
void dfs(ll i,ll pre,ll sum,ll b){
    if(i>n){
        if(b<3) return;
        if(sum>a[pre]*2) ans=(ans+1)%998244353;
        return;
    }
    dfs(i+1,pre,sum,b);
    dfs(i+1,i,sum+a[i],++b);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    cout<<ans%998244353;
    return 0;
}

