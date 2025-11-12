#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N],cnt,maxx,summ,ans,maxx2;
int ksm(int b,int p){
    int s=1ll;
    while(p){
        if(p&1ll)
            s=s*b%MOD;
        b=b*b%MOD;
        p>>=1ll;
    }
    return s;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]),maxx2=max(maxx2,a[i]);
    if(maxx2==1ll){
        printf("%lld\n",((ksm(2,n)+MOD-n)%MOD-1-(n*(n-1)/2)+MOD+MOD)%MOD);
        return 0;
    }
    sort(a,a+n);
    for(int i=0;i<(1<<n);i++){
        cnt=maxx=summ=0ll;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                maxx=max(maxx,a[j]),summ+=a[j],++cnt;
        if(cnt>2ll&&summ>2ll*maxx)
            ans=(ans+1ll)%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
