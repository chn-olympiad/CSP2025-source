#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
     ll l,r;
};
const int N=5e5+10;
ll n,k;
ll a[N];
vector<ll> ans;
ll vis[N];
ll cnt=1;
ll len;
node dp[N];
vector<ll> xb;
inline ll dfs(ll z){
    vis[z]=1;
    xb.push_back(dp[z].r);
    for(ll i=0;i<len/2;i++){
        if(i!=z){
            ll sd=1;
            for(ll j=0;j<xb.size();j++){
                if(dp[i].l<=xb[j]){
                    sd=0;
                    break;
                }
            }
            if(sd==1&&vis[i]!=1){
                cnt++;
                dfs(i);
            }
        }
    }
    return cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    bool is=true;
    bool is2=true;
    ll v=0;
    ll v2=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            is=false;
        }
        if(a[i]!=0&&a[i]!=1){
            is2=false;
        }
        if(a[i]==0){
            v++;
        }
        if(a[i]==1){
            v2++;
        }
    }
    if(is==true){
        if(k==0){
            cout<<n/2;
        }
        return 0;
    }
    if(is2==true){
        if(k==1){
            cout<<v2;
        }
        else{
            ll v3=0;
            for(ll i=1;i<n;i++){
                if(a[i]==1){
                    if(a[i+1]==1){
                        a[i]=0;
                        a[i+1]=0;
                        v3++;
                    }
                }
            }
            cout<<v+v3;
        }
        return 0;
    }
    for(ll i=1;i<=n;i++){
        ll op=0;
        for(ll j=i;j<=n;j++){
            if(i==j){
                op=a[j];
            }
            else{
                op=op^a[j];
            }
            if(op==k){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    len=ans.size();
    for(ll i=0;i<len/2;i++){
        dp[i].l=ans[i*2];
        dp[i].r=ans[i*2+1];
    }
    ll maxn=-1;
    for(ll i=0;i<len/2;i++){
        for(ll j=0;j<len/2;j++){
            vis[j]=0;
        }
        if(xb.size()!=0){
            for(ll j=0;j<xb.size();j++){
                xb.pop_back();
            }
        }
        maxn=max(dfs(i),maxn);
        cnt=1;
    }
    cout<<maxn;
    return 0;
}
