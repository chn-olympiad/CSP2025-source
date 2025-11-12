#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
    char ch=gc();
    for(;ch<'0'||ch>'9';ch=gc());
    for(x=0;ch>='0'&&ch<='9';ch=gc())
        x=(x<<1)+(x<<3)+(ch^48);
}
constexpr int _=505,mod=998244353;
int pw(int x,int y=mod-2){
    for(int v=1;;y>>=1,x=1ll*x*x%mod){
        if(!y)return v;
        if(y&1)v=1ll*v*x%mod;
    }
}
void Add(int &x,int y){if((x+=y)>=mod)x-=mod;}
int C[_][_],iC[_][_],ip[_];
void init(int M){
    for(int i=0;i<=M;++i)ip[i]=pw(i);
    C[0][0]=iC[0][0]=1;
    for(int i=1;i<=M;++i){
        C[i][0]=C[i][i]=iC[i][0]=iC[i][i]=1;
        for(int j=1;j<=M;++j){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
            iC[i][j]=pw(C[i][j]);
        }
    }
}
int n,m,a[_],c[_],e[_],h[_];
int f[_][_][_],ans;
void dfs(int x,int y){
    if(x>n)return Add(ans,y>=m),void();
    for(int i=x;i<=n;++i){
        std::swap(c[x],c[i]);
        dfs(x+1,y+(a[x]&&c[x]>x-1-y));
        std::swap(c[x],c[i]);
    }
}
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
    fio("employ");
    rd(n),rd(m);init(n);
    bool ok=1;
    for(int i=1;i<=n;++i){
        char ch=gc();
        if(i==1)for(;ch^'0'&&ch^'1';ch=gc());
        a[i]=ch-'0';
        if(!a[i])ok=0;
    }
    for(int i=1;i<=n;++i)rd(c[i]),++e[c[i]];
    if(n<=18){
        dfs(1,0);
        printf("%d\n",ans);
        return 0;
    }
    if(m==n){
        ans=1;
        for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
        for(int i=1;ok&&i<=n;++i)if(!c[i])ok=0;
        if(ok)printf("%d\n",ans);
        else printf("0\n");
        return 0;
    }
    if(ok){
        ans=1;
        for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;++i)h[i]=h[i-1]+e[i];
    f[0][0][0]=1;
    for(int i=0;i<n;++i)for(int j=0;j<=n;++j){
        for(int k=0;k<=i;++k){
            int u=f[i][j][k];
            if(!u)continue;
            // printf("%d %d %d %d\n",i,j,k,u);
            if(!a[i+1]){
                for(int p=0;p<=e[j]&&k+p<=i;++p){
                    if(i-k-p<0||h[j]-k-p<0||n-h[j]-(i-k-p)<0)continue;
                    int q=1ll*u*C[e[j]][p]%mod*iC[n-h[j-1]][i-k]%mod;
                    Add(f[i+1][j+1][k+p],1ll*q*(n-h[j]-(i-k-p))%mod);
                    Add(f[i+1][j+1][k+p+1],1ll*q*(h[j]-k-p)%mod);
                }
            }
            else{
                if(n-h[j-1]-(i-k)>=0)
                    Add(f[i+1][j][k],1ll*u*(n-h[j-1]-(i-k))%mod);
                for(int p=0;p<=e[j];++p){
                    int q=1ll*u*C[e[j]][p]%mod*iC[n-h[j-1]][i-k]%mod;
                    // printf("  %d %d %d %d\n",u,q,C[e[j]][p],C[n-h[j-1]][i-k]);
                    Add(f[i+1][j+1][k+p],1ll*q*(h[j-1]-k)%mod);
                }
            }
        }
    }
    for(int j=0;j<=n-m;++j)for(int k=0;k<=n;++k)
        Add(ans,f[n][j][k]);
    printf("%d\n",ans);
}