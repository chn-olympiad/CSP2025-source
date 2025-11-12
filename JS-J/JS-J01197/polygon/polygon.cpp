#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m=998244353;
int n;
int a[5005];
ll fac[5005],inv[5005];

ll poww(ll a,ll b){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

ll C(int n,int r){
    if(r>n)return 0;
    return (fac[n]*inv[n-r]%m)*inv[r]%m;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    fac[0]=1;
    inv[0]=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        fac[i]=fac[i-1]*i%m;
        inv[i]=poww(fac[i],m-2);
    }
    sort(a+1,a+n+1);
    if(a[1]==a[n]){
        ll k=poww(2,n)-C(n,0)-C(n,1)-C(n,2);
        printf("%lld",k);
        return 0;
    }
    for(int i=0;i<(1<<n);i++){
        ll sum=0;
        int maxn=0;
        for(int j=1;j<=n;j++){
            if((i>>(j-1))&1){
                sum+=a[j];
                maxn=max(maxn,j);
            }
        }
        if(sum>2*a[maxn]){
            ans=(ans+1)%m;
        }
    }
    printf("%lld",ans);
    return 0;
}
