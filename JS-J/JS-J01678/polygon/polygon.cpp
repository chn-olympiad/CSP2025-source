#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,cnt;
const int N=5005,mod=998244353;
int a[N],b[N*2];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    b[0]=1;
    for(int i=1;i<=n;i++){
        ans=(ans+cnt)%mod;
        cnt*=2;
        for(int j=10000;j>=0;j--){
            if(b[j]==0)continue;
            int nx=j+a[i];
            if(nx>2*a[i])ans=(ans+b[j])%mod;
            if(nx>10000)cnt=(cnt+b[j])%mod;
            else b[nx]=(b[nx]+b[j])%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
