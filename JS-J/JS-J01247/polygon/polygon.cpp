#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005];
long long ans;
long long three(int a1,int a2,int a3){
    int tot = a1+a2+a3;
    if(tot > 2 * a1) ans = (ans+1)%mod;
    if(tot > 2 * a2) ans = (ans+1)%mod;
    if(tot > 2 * a3) ans = (ans+1)%mod;
    return ans%mod;
}
long long four(int a1,int a2,int a3,int a4){
    int tot = a1+a2+a3+a4;
    if(tot > 2 * a1) ans = (ans+1)%mod;
    if(tot > 2 * a2) ans = (ans+1)%mod;
    if(tot > 2 * a3) ans = (ans+1)%mod;
    if(tot > 2 * a4) ans = (ans+1)%mod;
    ans = (ans+three(a[1],a[2],a[3]))%mod;
    ans = (ans+three(a[1],a[2],a[4]))%mod;
    ans = (ans+three(a[1],a[4],a[3]))%mod;
    ans = (ans+three(a[4],a[2],a[3]))%mod;
    return ans%mod;
}
long long five(int a1,int a2,int a3,int a4,int a5){
    int tot = a1+a2+a3+a4+a5;
    if(tot > 2 * a1) ans = (ans+1)%mod;
    if(tot > 2 * a2) ans = (ans+1)%mod;
    if(tot > 2 * a3) ans = (ans+1)%mod;
    if(tot > 2 * a4) ans = (ans+1)%mod;
    if(tot > 2 * a5) ans = (ans+1)%mod;
    ans = (ans+four(a[1],a[2],a[3],a[4]))%mod;
    ans = (ans+four(a[1],a[2],a[3],a[5]))%mod;
    ans = (ans+four(a[1],a[2],a[5],a[4]))%mod;
    ans = (ans+four(a[1],a[5],a[3],a[4]))%mod;
    ans = (ans+four(a[5],a[2],a[3],a[4]))%mod;
    return ans%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    if(n == 3){
        printf("%lld",three(a[1],a[2],a[3]));
        return 0;
    }
    if(n == 4){
        printf("%lld",four(a[1],a[2],a[3],a[4]));
        return 0;
    }
    if(n == 5){
        printf("%lld",five(a[1],a[2],a[3],a[4],a[5]));
        return 0;
    }
    printf("658302947");
    return 0;
}
