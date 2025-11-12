#include <bits/stdc++.h>
using namespace std;
long long a[5*100000+1];
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long b=a[1];
    for(long long i=2;i<=n;i++){
        if(b==k){
            ans++;
            b=a[i];
        }else b^=a[i];
    }
    if(b==k) ans++;
    printf("%lld",ans);
}
