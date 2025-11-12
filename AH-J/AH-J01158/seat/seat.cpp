#include <bits/stdc++.h>;
using namespace std;
typedef long long LL;
const LL N=2*10*10+10;
LL n,m;
LL a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    LL fs=a[1],pos;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==fs) pos=i;
    }
    LL r,c;
    if(pos%n==0){
        c=pos/n;
    }
    else{
        c=pos/n+1;
    }
    if(pos%n==0){
        if(c%2!=0) r=n;
        else r=1;
    }
    if(pos%n!=0){
        if(c%2!=0){
            r=pos%n;
        }
        else{
            r=n-pos%n+1;
        }
    }
    printf("%lld %lld",c,r);
    return 0;
}
