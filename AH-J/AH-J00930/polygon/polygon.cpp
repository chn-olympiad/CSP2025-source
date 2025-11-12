#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,C[5005][5005],a[5005],k,ans,sum2[5005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<=n;i++) C[1][i]=i,C[0][i]=1;
    for(int i=2;i<=n;i++) for(int j=i;j<=n;j++) C[i][j]=(C[i][j-1]+C[i-1][j-1])%mod;
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=1;j<=i;j++) k=(k+C[j-1][i-1])%mod;
        ans=(ans+k)%mod;
    }
    sort(a+1,a+n+1);
    sum2[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++) ans=(ans-sum2[j]+mod)%mod;
        for(int j=5000-a[i];j>=0;j--) sum2[j+a[i]]=(sum2[j+a[i]]+sum2[j])%mod;
    }
    printf("%lld",ans);
    return 0;
}
