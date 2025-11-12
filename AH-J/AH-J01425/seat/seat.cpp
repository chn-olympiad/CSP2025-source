#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=110;
LL n,m,a[N],R;
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1; i<=n*m; i++) scanf("%lld",&a[i]);
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    LL pos;
    for(LL i=1; i<=n*m; i++) if(a[i]==R) pos=i;
    LL x,y,t=pos/n;
    if(pos%n==0) x=t;
    else x=t+1;
    if(x%2!=0){
        LL last=(x-1)*n;
        for(LL i=1; i<=n; i++){
            last++;
            if(last==pos) y=i;
        }
    }
    else{
        LL last=(x-1)*n;
        for(LL i=n; i>=1; i--){
            last++;
            if(last==pos) y=i;
        }
    }
    printf("%lld %lld",x,y);
    return 0;
}
