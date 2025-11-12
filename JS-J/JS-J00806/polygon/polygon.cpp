#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000],s[100000];
ll n,ans=0;
void dfs(ll sum,ll b,ll i){
    if(a[i]<sum&&b>=3) ans=(ans+1)%998244353;
    for(ll j=i+1;j<=n;j++){
        dfs(sum+a[i],b+1,j);
    }
    return;
 }
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    sort(a,a+n+1);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
