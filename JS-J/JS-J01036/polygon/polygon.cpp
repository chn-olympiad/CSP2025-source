#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010,mod=998244353;
ll n,ans;
ll a[N],b[N],v[N];
void dfs(ll k,ll m){
    if(k>m){
        bool f=1;
        for(ll i=1;i<k;i++){
            if(b[i]<=b[i-1])
                return;
        }
        ll sum=0,maxn=a[b[k-1]]*2;
        for(ll i=1;i<k;i++){
            sum+=a[b[i]];
        }
        if(sum>maxn){
            ans++;
            ans=ans%mod;
        }
        return;
    }
    for(ll i=k;i<=n;i++){
        if(v[i]==0){
            b[k]=i,v[i]=1;
            dfs(k+1,m);
            v[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=3;i<=n;i++)
        dfs(1,i);
    cout<<ans;
    return 0;
}
