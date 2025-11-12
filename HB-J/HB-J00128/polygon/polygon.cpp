#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,a[N];
int mo=998244353,f[N]={1},sum=0;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%mo;
    }
    for(int i=3;i<=n;i++){
        sum+=(n-i+1)*f[i]%mo;sum=sum%mo;
    }
    printf("%lld",sum);
    return 0;
}