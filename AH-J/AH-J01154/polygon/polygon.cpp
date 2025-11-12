#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+10;
LL n,a[N],cnt=0;
void Count(LL cur,LL sum,LL maxn){
    if(cur>n){
        if(sum>maxn*2) cnt=(cnt+1)%998244353;
        return;
    }
    Count(cur+1,sum,maxn);
    Count(cur+1,sum+a[cur],max(maxn,a[cur]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    Count(1,0,0);
    cout<<cnt%998244353;
    return 0;
}
