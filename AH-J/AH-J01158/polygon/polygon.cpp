#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5100;
LL n,cnt,maxn=-1e18;
LL a[N];
bool check(LL n){
    LL sum=0,maxn=-1e18;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(sum>2*maxn) return true;
    return false;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(check(3)) cout<<1;
    else cout<<0;
    return 0;
}
