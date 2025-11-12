#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+10,MOD=998244353;
LL n,cnt,a[N];
bool check(LL x,LL y){
    LL sum=0,maxn=0;
    for(LL i=x;i<=y;i++){
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    return sum>maxn*2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(LL i=1;i<=n;i++)
        for(LL j=1;j<=n;j++)
            if(check(i,j)) cnt=(cnt+1)%MOD;
    printf("%lld",cnt);
    return 0;
}
