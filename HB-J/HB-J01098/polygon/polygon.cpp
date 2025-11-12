#include<bits/stdc++.h>
#define ll long long
#define lxx 0
using namespace std;
ll a[5005],n,ans=0;
void dfs(ll dep,ll maxn,ll sum,ll sl){
    // cout<<dep<<" ";
    if(dep==n+1){
        if(sl>=3 && sum>2*maxn){
        //    cout<<"over"<<endl;
            ans++;
        }
        return;
    }
    dfs(dep+1,max(maxn,a[dep]),sum+a[dep],sl+1);
    dfs(dep+1,maxn,sum,sl);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,-1,0,0);
        cout<<ans<<"\n";
        return lxx;
    }else{
        ll ans=0;
        for(ll i=n;i>=3;i--){
            ll nans=1;
            for(int j=n;j>=max(n-i+1,i);j--){
                nans*=j;
            }
            for(int j=min(n-i+1,i);j>=1;j--){
                nans/=j;
            }
            ans+=nans;
        }
        cout<<ans<<"\n";
        return lxx;
    }
}