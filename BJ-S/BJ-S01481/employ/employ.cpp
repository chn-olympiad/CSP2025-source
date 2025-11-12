#include <cstdio>
const long long MOD=998244353;
long long dp[20][262154];
int f[2][103][103][103];
long long jc[107],inv[107],b[107],c[107];
int a[107];
long long C(long long x,long long y){
    return jc[x]*inv[y]%MOD*inv[x-y]%MOD;
}
long long ksm(long long x,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*x)%MOD;
        x=(x*x)%MOD;
        k>>=1;
    }
    return res;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    jc[0]=1;
    for(long long i=1;i<=n;i++) jc[i]=jc[i-1]*i%MOD;
    inv[n]=ksm(jc[n],MOD-2);
    for(long long i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%MOD;
    long long sum=0;
    for(long long i=1;i<=n;i++){
        scanf("%1d",&a[i]);
        sum+=a[i];
    }
    bool flag=false;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        if(!c[i]) flag=true;
        b[c[i]]++;
    }
    if(m==n){
        if(sum==n && !flag){
            long long ans=1;
            for(long long i=1;i<=m;i++) (ans*=i)%=MOD;
            printf("%lld",ans);
        }else printf("0");
        return 0;
    }
    if(n<=18){    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int k=0;k<=i;k++){
            for(int msk=0;msk<(1<<n);msk++){
                if(__builtin_popcount(msk)!=i) continue;
                for(int j=0;j<n;j++){
                    if(!(msk&(1<<j))){
                        int nxt=msk|(1<<j);
                        if(!a[i+1] || i-k>=c[j+1]) (dp[k][nxt]+=dp[k][msk])%=MOD;
                        else (dp[k+1][nxt]+=dp[k][msk])%=MOD;
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=m;i<=n;i++) (ans+=dp[i][(1<<n)-1])%=MOD;
    printf("%lld",ans);
    return 0;}
    // if(sum==n){
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            if(!c[i]) cnt++;
        }
        f[0][0][0][cnt]=1;
        for(long long i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    for(int l=0;l<=n;l++){
                        f[(i+1)&1][j][k][l]=0;
                    }
                }
            }
            for(long long j=0;j<=i;j++){
                for(long long k=0;k<=j;k++){
                    for(long long l=0;l<=n-i+k && l<=n;l++){
                        for(long long p=0;p<=b[i-j+1] && p<=k;p++){
                            (f[(i+1)&1][j][k-p][l-1+b[i-j+1]-p]+=1ll*f[i&1][j][k][l]*C(b[i-j+1],p)%MOD*C(k,p)%MOD*jc[p]%MOD*l%MOD)%=MOD;
                        }
                        if(a[i+1]){
                            if((n-(i-k))-l>0){
                                (f[(i+1)&1][j+1][k+1][l]+=f[i&1][j][k][l])%=MOD;
                            }
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(long long i=0;i<=n;i++){
            for(long long j=m;j<=n;j++){
                (ans+=1ll*f[n&1][j][i][0]*jc[i]%MOD)%=MOD;
            }
        }
        printf("%lld",ans);
    //     return 0;
    // }

    return 0;
}