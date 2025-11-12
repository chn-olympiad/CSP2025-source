#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000010],k;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    if(n<=2){
        printf("0");
    }
    else if(n==3){
        if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[3]+a[2]>a[1]) printf("1");
        else printf("0");
    }
    else{
        printf("%lld",n);
    }
    return 0;
}


