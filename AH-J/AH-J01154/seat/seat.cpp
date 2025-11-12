#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110],h;
bool cmp(LL x,LL y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n*m;i++) scanf("%lld",&a[i]);
    h=a[1];
    sort(a+1,a+1+n*m,cmp);
    LL x=1,y=1;
    for(LL i=1;i<=n*m;i++){
        if(a[i]==h) break;
        if(x%2==1){
            y++;
            if(y>n) x++,y=n;
        }else{
            y--;
            if(y<1) x++,y=1;
        }
    }
    printf("%lld %lld",x,y);
    return 0;
}
