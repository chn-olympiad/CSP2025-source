#include<bits/stdc++.h>
#define ll long long
#define u unsigned
using namespace std;
const ll mod=998244353;
int n,a[5005];
ll ans;
void dg(int x,ll s,int mx){
    if(x==n){
        if(s-mx>mx){
            ans++;
            ans%=mod;
        }
        return;
    }
    dg(x+1,s,mx);
    dg(x+1,s+a[x+1],max(mx,a[x+1]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    dg(1,0,0);
    dg(1,a[1],a[1]);
    printf("%lld",ans%mod);
    return 0;
}
