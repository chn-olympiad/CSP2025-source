#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 100 ;
const ll MOD = 998244353 ;
int n,a[N],k,vis[N];
ll ans;
bool check(){
    ll res=0;
    int amax=0;
    for(int i=1;i<=k;i++){
        res+=vis[i];
        amax=max(amax,vis[i]);
    }
    return res>2*amax;
}
void dfs(int id,int deep){
    if(deep==k){
        vis[deep]=a[id];
        if(check()){
            ans++;
        }
        return;
    }
    vis[deep]=a[id];
    for(int i=id+1;i<=n;i++){
        dfs(i,deep+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<1;
        }
        else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++){
        k=i;
        for(int i=1;i<=n;i++){
            dfs(i,1);
        }
    }
    cout<<ans%MOD;
    return 0;
}
