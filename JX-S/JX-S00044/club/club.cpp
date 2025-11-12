#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define M 1010
using namespace std;
ll a[1010][5],w[9],e[9],r[9],n,s,d;
void dfs(ll t,ll x,ll c,ll v){
    if(x>n/2||c>n/2||v>n/2){
        return;
    }
    if(t==n+1){
        s=max(s,d);
        return;
    }
    d+=a[t][1];
    dfs(t+1,x+1,c,v);
    d-=a[t][1];
    d+=a[t][2];
    dfs(t+1,x,c+1,v);
    d-=a[t][2];
    d+=a[t][3];
    dfs(t+1,x,c,v+1);
    d-=a[t][3];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
   // if(n<=10){
        dfs(1ll,0ll,0ll,0ll);
        cout<<s<<endl;
    //}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        s=0;
        d=0;
        memset(a,0,sizeof(a));
        solve();
    }
    return 0;
}
