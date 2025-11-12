#include<bits/stdc++.h>
const int N=500,mod=998244353;
int n,m,t[N+5];
char st[N+5];
int f[2][N+5][N+5],qz[N+5],jc[N+5],inv[N+5],ans;
void cplus(int &x,int y){x+=y,x>=mod?x-=mod:0;}
int C(int x,int y){return x<y?0:1ll*jc[x]*inv[y]%mod*inv[x-y]%mod;}
int A(int x,int y){return x<y?0:1ll*jc[x]*inv[x-y]%mod;}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",st+1);
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    jc[0]=inv[0]=1;
    for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod;
    for(int i=1,x;i<=n;++i)scanf("%d",&x),++t[x];
    for(int i=0;i<=n;++i)qz[i]=t[i];
    for(int i=1;i<=n;++i)qz[i]+=qz[i-1];
    int o=0;
    f[0][0][0]=1;
    int ss=0;
    for(int i=1;i<=n;++i){
        int z=o^1;
        for(int j=0;j<=i;++j){
            for(int k=0;k<=j;++k)f[z][j][k]=0;
        }
        for(int j=0;j<=i;++j){
            for(int k=0;k<=j;++k)if(f[o][j][k]){
                int s=0;
                if(st[i]=='0')s=f[o][j][k];
                else if(qz[i-1-j]>ss-k)s=1ll*f[o][j][k]*(qz[i-1-j]-(ss-k))%mod;
                for(int l=0;l<=k&&l<=t[i-j];++l){
                    cplus(f[z][j][k-l],1ll*s*A(k,l)%mod*C(t[i-j],l)%mod);
                }
                if(st[i]=='1')cplus(f[z][j+1][k+1],f[o][j][k]);
            }
        }
        if(st[i]=='1')++ss;
        //for(int j=0;j<=i;++j){
        //    for(int k=0;k<=j;++k)printf("%d ",f[z][j][k]);
        //    printf("\n");
        //}
        //printf("\n");
        o=z;
    }
    for(int j=m;j<=n;++j){
        for(int k=0;k<=j;++k)if(f[o][j][k]){
            //printf("%d %d %d\n",j,k,f[o][j][k]);
            cplus(ans,1ll*f[o][j][k]*A(qz[n]-qz[n-j],k)%mod);
        }
    }
    int cn=0;
    for(int i=1;i<=n;++i)if(st[i]=='0')++cn;
    ans=1ll*ans*jc[cn]%mod;
    printf("%d\n",ans);
    return 0;
}