#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;

long long a[5010];
long long C(long long n,long long m){
    long long sum=1;
    for (long long i=1;i<=m;i++){
        sum=sum*(n-i+1)%mod;
    }
    for (long long i=1;i<=m;i++){
        sum=sum/i%mod;
    }
    return sum;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    bool spe=1;
    for (long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if (a[i]!=a[1]){
            spe=0;
        }
    }
    if (n<3){
        printf("0");
        return 0;
    }
    if (n==3){
        if ((a[1]+a[2]+a[3])>2*max(max(a[1],a[2]),a[3])){
            printf("1");
            return 0;
        }
        else{
            printf("0");
            return 0;
        }
    }
    if (spe && n>=3){
        long long ans=0;
        for (long long i=3;i<=n;i++){
            ans=ans+C(n,i)%mod;
        }
        printf("%lld",ans);
        return 0;
    }
    return 0;
}

