#include<bits/stdc++.h>
using namespace std;
long long a[110];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,f,i;
    scanf("%lld%lld",&n,&m);
    m*=n;
    for(i=1;i<=m;i++){
        scanf("%lld",&a[i]);
    }
    f=a[1];
    sort(a+1,a+1+m,cmp);
    for(i=1;i<=m;i++){
        if(a[i]==f) break;
    }
    printf("%lld ",(i-1)/n+1);
    if((i-1)/n%2==0){
        printf("%lld",(i-1)%n+1);
    }
    else{
        printf("%lld",n-(i-1)%n);
    }
    return 0;
}
