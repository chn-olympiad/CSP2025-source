#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e2+10;
LL R,a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m,c,r,t=1;
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n*m;i++) scanf("%lld",&a[i]);
    R=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(LL i=1;i<=m;i++){
        if(i%2==1){
            for(LL j=1;j<=n;j++){
                if(a[t]==R){
                    c=i,r=j;
                    printf("%lld %lld",c,r);
                    return 0;
                }
                t++;
            }
        }
        else{
            for(LL j=n;j>=1;j--){
                if(a[t]==R){
                    c=i,r=j;
                    printf("%lld %lld",c,r);
                    return 0;
                }
                t++;
            }
        }
    }
    return 0;
}
