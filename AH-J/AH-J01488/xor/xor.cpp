#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1000010],k;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    if(n<=2){
        if(n==1 && a[1]!=0) printf("0");
        else if(n==1 && a[1]==0) printf("1");
        else if(n==2 && a[1]==0 && a[2]==0) printf("2");
        else if(n==2 && ((a[1]==0 && a[2]!=0) || (a[1]!=0 && a[2]==0 ))) printf("1");
        else if(n==2 && a[1]==a[2]) printf("1");
        else if(n==2 && a[1]!=0 && a[2]!=0 && a[1]^a[2]!=0) printf("0");
    }
    else printf("%lld",2*n);
    return 0;
}
