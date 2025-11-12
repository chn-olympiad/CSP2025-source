#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
int a[6000],n;
ll ans;
ll quick_pow(int p){
    ll res=1,x=2;
    while(p){
        if(p%2)res*=x;
        x*=2;
        p/=2;
    }
    return res;
}
void dfs(int dep,int num,int sum,int maxn){
    if(dep==n){
        if(num>=3&&sum>2*maxn)ans=(ans+1)%mod;
        return;
    }
    int pos=dep+1;
    dfs(dep+1,num,sum,maxn);
    dfs(dep+1,num+1,sum+a[pos],max(maxn,a[pos]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*2%mod;
        }
        ans=(ans-1)%mod;ans=(ans-n)%mod;ans=(ans-n*(n-1)/2)%mod;
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
