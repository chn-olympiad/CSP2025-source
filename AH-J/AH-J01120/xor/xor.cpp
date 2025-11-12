#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,a[N],ac[N],ans,dp[N],maxn;
struct node{
    ll l,r;
}dis[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ac[i]=(ac[i-1]^a[i]);
    }
    for(ll i=1;i<=n;i++)
        for(ll j=i;j<=n;j++)
            if((ac[i-1]^ac[j])==k){
                ans++;
                dis[ans].l=i;
                dis[ans].r=j;
                break;
            }
    for(ll i=1;i<=ans;i++){
        dp[i]=1;
        for(ll j=i-1;j>=1;j--)
            if(dis[j].r<dis[i].l){
                dp[i]=max(dp[i],dp[j]+1);
                break;
            }
        maxn=max(maxn,dp[i]);
    }
    cout<<maxn;
    return 0;
}
