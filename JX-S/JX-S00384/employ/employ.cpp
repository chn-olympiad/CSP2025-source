#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

ll n,m,del;
ll a[600],v[600];
ll s[600],c[600];

ll dfs(ll now){
    if(now>n) return del<=n-m;
    ll res=0;
    for(ll i=1;i<=n;i++)
    if(!v[i]){
        v[i]=1;
        a[now]=i;
        bool flag=0;
        if(del>=c[i]||s[now]==0) flag=1;
        if(flag) del++;
        (res+=dfs(now+1))%=mod;
        if(flag) del--;
        a[now]=0;
        v[i]=0;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        char x;cin>>x;
        s[i]=x-'0';
    }
    for(ll i=1;i<=n;i++)
    cin>>c[i];
    cout<<dfs(1);
    return 0;
}