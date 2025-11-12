#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m[5005],ans=0;
ll dfs(ll x,ll sm,ll mx,ll ct){
    if(x==n){
        //cout<<sm<<' '<<mx<<' '<<ct<<'\n';
        if(sm>mx*2&&ct>=3)return 1;
        return 0;
    }
    return (dfs(x+1,sm,mx,ct)+dfs(x+1,sm+m[x],max(mx,m[x]),ct+1))%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>m[i];
    if(n<=20){
        ans=dfs(0,0,0,0);
    }else{
        ans=1;
        for(int i=0;i<n-2;i++){
            ans=ans*2%mod;
        }
    }
    cout<<ans;
    return 0;
}
