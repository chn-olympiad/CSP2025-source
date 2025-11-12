#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
struct node{
    ll num;
    ll va;
}d[4];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    for(ll r=0;r<t;r++){
        ll ans=0;
        scanf("%lld",&n);
        ll maxn=n/2,a[n+5]={};
        for(ll i=1;i<=n;i++){
            scanf("%lld%lld%lld",&d[1].va,&a[i],&d[3].va);
        }
        sort(a+1,a+n+1,cmp);
        for(ll i=1;i<=maxn;i++){
            ans+=a[i];
        }
        printf("%lld",ans);
    }
    return 0;
}
