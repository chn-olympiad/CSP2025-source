#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,x[N],xum[N],tot,R,ans=1;
struct Node{
    LL l,r;
}a[N];
bool cmp(const Node &x,const Node &y){
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&x[i]);
        xum[i]=xum[i-1]^x[i];
    }
    for(LL r=1;r<=n;r++)
        for(LL l=1;l<=r;l++)
            if((xum[r]^xum[l-1])==k){
                tot++;
                a[tot].l=l;
                a[tot].r=r;
            }
    R=a[1].r;
    for(LL i=2;i<=tot;i++){
        if(R>a[i].r)   R=a[i].r;
        if(R<a[i].l){
            ans++;
            R=a[i].r;
        }
    }
    printf("%lld ",ans);
    return 0;
}
