#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[20],exam[20][20],R,s;
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
        if(i==1) R=a[i];
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(LL l=1;l<=m;l++){
        for(LL h=1;h<=n;h++){
            if(l%2!=0) exam[h][l]=a[++s];
            else exam[n-h+1][l]=a[++s];
        }
    }
    LL h=1,l=1;
    bool ok=true;
    while(l<=m){
        if(exam[h][l]==R){
            printf("%lld %lld",l,h);
            break;
        }
        if(ok) h++;
        else if(!ok) h--;
        if(ok&&h==n+1){
            h=n;l++;
            ok=false;
        }
        else if(!ok&&h==0){
            h=1;l++;
            ok=true;
        }
    }
    return 0;
}
