#include<bits/stdc++.h>
using namespace std;
#define N 505
#define p 998244353
#define ll long long
char s[N];
int n,m,c[N],pr[N];
ll f[2][N][N],fac[N],inv[N],ifac[N];
void upd(ll &x,ll y){
    (x+=y)%=p;
}
ll C(int n,int m){
    return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
    for(int i=2;i<N;i++){
        fac[i]=fac[i-1]*i%p;
        inv[i]=inv[p%i]*(p-p/i)%p;
        ifac[i]=ifac[i-1]*inv[i]%p;
    }
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        c[x]++;
    }
    pr[0]=c[0];for(int i=1;i<=n;i++)pr[i]=pr[i-1]+c[i];
    f[0][0][c[0]]=1;
    for(int i=0;i<n;i++){
        memset(f[i+1&1],0,sizeof(f[i+1&1]));
        for(int j=0;j<=n;j++){
            for(int l=0;l<=n;l++)if(f[i&1][j][l]){
                int k=i-(pr[j]-l);
                if(l){
                    for(int h=0;h<=c[j+1];h++)if(c[j+1]-h<=k)
                        upd(f[i+1&1][j+1][l-1+h],f[i&1][j][l]*C(c[j+1],h)%p*l%p*fac[k]%p*ifac[k-(c[j+1]-h)]);
                }
                if(s[i+1]=='1')upd(f[i+1&1][j][l],f[i&1][j][l]);
                else{
                    ++k;
                    for(int h=0;h<=c[j+1];h++)if(c[j+1]-h<=k)
                        upd(f[i+1&1][j+1][l+h],f[i&1][j][l]*C(c[j+1],h)%p*fac[k]%p*ifac[k-(c[j+1]-h)]);
                }
            }
        }
    }
    ll ans=0;
    for(int j=0;j<=n-m;j++)if(f[n&1][j][0]){
        int k=n-pr[j];
        upd(ans,f[n&1][j][0]*fac[k]);
    }
    printf("%lld\n",ans);
}
/*
4:50 ak
so boring,this time the problems are so easy. 
*/
