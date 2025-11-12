#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+10;
LL n,m,k,p,a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n*m;i++) scanf("%lld",a+i);
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(LL i=1;i<=n*m;i++) if(a[i]==k){p=i;break;}
    LL c=p/n,r=0;
    if(c*n!=p) c++;
    if(c%2!=0){
        LL lou=(c-1)*n;
        for(LL i=lou+1;i<=lou+n;i++) if(a[i]==k) r=i;
    }
    else{
        LL lou=(c-1)*n;
        for(LL i=lou+n;i>=lou;i--) if(a[i]==k) r=i;
    }
    printf("%lld ",c);
    if(r>n) printf("%lld",r-(r-n));
    else printf("%lld",r);
    return 0;
}
