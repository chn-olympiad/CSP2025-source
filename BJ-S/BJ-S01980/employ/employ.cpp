#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m;
char a[N];
int qzh[N];
int c[N],cnt[N];
int fac[N],C[N][N];
void ad(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int f[N][N][N];
int ff[N][N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0]=1;
    for(int i=1;i<=500;i++)fac[i]=1LL*fac[i-1]*i%mod;
    for(int i=0;i<=500;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],qzh[i]=qzh[i-1]+(a[i]=='1');
    for(int i=1;i<=n;i++)
        cin>>c[i],cnt[c[i]]++;
    for(int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];
    f[1][0][0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]=='0'){
            for(int jt=0;jt<=n;jt++){
                for(int k=0;k<=n;k++){
                    if(f[i][jt][k]==0)continue;
                    //cout<<i<<" "<<jt<<" "<<k<<" "<<f[i][jt][k]<<'\n';
                    int l=qzh[i-1]-k;
                    for(int p=0;p<=cnt[jt+1]-cnt[jt];p++){
                        int q=cnt[jt+1]-cnt[jt];
                        if(l<p)break;
                        ad(f[i+1][jt+1][k+p],1LL*f[i][jt][k]*C[q][p]%mod*C[l][p]%mod*fac[p]%mod);
                    }
                }
            }
        }
        else{
            for(int jt=0;jt<=n;jt++){
                for(int k=0;k<=n;k++){
                    if(f[i][jt][k]==0)continue;
                    //cout<<i<<" "<<jt<<" "<<k<<" "<<f[i][jt][k]<<'\n';
                    //choose
                    int l=qzh[i-1]-k;
                    if(n-cnt[jt]>l)
                        ad(f[i+1][jt][k],f[i][jt][k]);
                    //not choose
                    for(int p=0;p<=cnt[jt+1]-cnt[jt];p++){
                        int q=cnt[jt+1]-cnt[jt];
                        if(l<p)break;
                        ad(f[i+1][jt+1][k+p+1],1LL*f[i][jt][k]*C[q][p]%mod*C[l][p]%mod*fac[p]%mod*(cnt[jt]-k)%mod);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int jt=0;jt<=n-m;jt++)
        for(int k=0;k<=n;k++){
            int l=qzh[n]-k;
            int q=n-cnt[jt];
            if(q<0||l<0)continue;
            //cout<<"::"<<n+1<<" "<<jt<<" "<<k<<" "<<l<<" "<<f[n+1][jt][k]<<'\n';
            ad(ans,1LL*f[n+1][jt][k]*C[q][l]%mod*fac[l]%mod);
        }
    cout<<1LL*ans*fac[n-qzh[n]]%mod;
    return 0;
}
