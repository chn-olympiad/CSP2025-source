#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const int mod=998244353;
ll n,res,arr[maxn],vis[maxn],brr[maxn];
map<pair<ll,ll>,bool> m;
void dfs(ll k,ll step,ll sum,ll max1,ll s1,ll s2){
    if(step+1==k){
        pair<ll,ll> temp={s1,s2};
        if(sum>2*max1&&!m[temp]){
            m[temp]=true;
            res=(res+1)%mod;
            //for(int i=1;i<k;i++) cout<<brr[i]<<' ';
            //cout<<'\n';
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            brr[step+1]=i;
            vis[i]=true;
            dfs(k,step+1,sum+arr[i],max(max1,arr[i]),s1+(i+97),s2+(i*48));
            vis[i]=false;
        }
    }
    return;
}
ll quickly_pow(ll a,ll p){
    ll res=1;
    while(p){
        if(p%2==1) res=res*a%mod;
        a=a*a%mod;
        p=p/2;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll flag=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        flag=max(flag,arr[i]);
    }
    if(flag==1){
        res=(quickly_pow(2,n)-1+mod-(n*(n-1)/2)%mod-1)%mod;
    }
    else{
        for(int k=4;k<=n+1;k++){
            dfs(k,0,0,0,0,0);
            for(int i=1;i<=k;i++) vis[i]=false;
        }
    }
    cout<<res;
    return 0;
}
