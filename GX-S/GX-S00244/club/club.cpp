#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll n,m,a[100010],b[100010],c[100010];
ll dfs(ll ax,ll bx,ll cx,ll s){
    ll sum=0;
    if(s==n){
        if(ax<m) sum=max(sum,a[s]);
        if(bx<m) sum=max(sum,b[s]);
        if(cx<m) sum=max(sum,c[s]);
        return sum;
    }
    if(ax<m) sum=max(sum,dfs(ax+1,bx,cx,s+1)+a[s]);
    if(bx<m) sum=max(sum,dfs(ax,bx+1,cx,s+1)+b[s]);
    if(cx<m) sum=max(sum,dfs(ax,bx,cx+1,s+1)+c[s]);
    return sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(ll e=1;e<=t;e++){
        cin>>n;
        m=n/2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        bool fa=1,fb=1;
        for(ll i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0) fa=0;
            if(c[i]!=0) fa=0,fb=0;
        }
        if(fa){
            sort(a+1,a+1+n);
            ll ans=0;
            for(ll i=1;i<=m;i++) ans+=a[n-i+1];
            cout<<ans<<endl;
        }
        else{
            cout<<dfs(0,0,0,1)<<endl;
        }
    }
    return 0;
}
