#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,ans,maxx;
long long a[5005],pre[5005];
bool b[5005];
void dfs(int x,long long ma,long long sum){
    if(x==n+1){
        if(sum>2*ma)ans++;
        return;
    }
    if(2*ma>=sum+pre[x])return;
    b[x]=0;
    dfs(x+1,ma,sum);
    b[x]=1;
    sum+=a[x];
    ma=max(ma,a[x]);
    dfs(x+1,ma,sum);
}
long long qpow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
    }
    for(int i=n;i>=1;i--)pre[i]=pre[i+1]+a[i];
    if(maxx==1){
        printf("%lld",(qpow(2,n)-n-1-(n*(n-1)/2%mod)+mod)%mod);
        return 0;
    }
    dfs(1,0,0);
    printf("%lld",ans%mod);
    return 0;
}
