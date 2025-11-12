#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){x=0;int f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();x*=f;}
template<typename T> inline void write(T x){if(x>9)write(x/10);putchar(x%10+'0');}
const int N=501,mod=998244353;
int n,m,c[N],sum[N],pos[N],cnt;
int f[2][1<<18][20];
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read(n),read(m);
    scanf("%s",s+1);
    int flag=1;
    for(int i=1;i<=n;++i)read(c[i]),flag&=(s[i]=='1');
    if(flag){
        int ans=1;
        for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
        write(ans);return 0;
    }
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]=='0');
    for(int i=1;i<=n;++i)if(s[i]=='1')pos[++cnt]=i;
    f[0][0][0]=1;
    for(int i=0;i<n;++i){
        for(int ss=0;ss<(1<<n);++ss)for(int j=0;j<=m;++j)
            f[(i+1)&1][ss][j]=0;
        for(int ss=0;ss<(1<<n);++ss)
            for(int j=0;j<=m;++j)if(f[i&1][ss][j]){
                for(int p=1;p<=n;++p)if(!((ss>>(p-1))&1)){
                    if(s[p]=='1'&&sum[p]<c[i+1])
                        f[(i+1)&1][ss|(1<<(p-1))][j+1]=(1ll*f[(i+1)&1][ss|(1<<(p-1))][j+1]+f[i&1][ss][j])%mod;
                    else
                        f[(i+1)&1][ss|(1<<(p-1))][j]=(1ll*f[(i+1)&1][ss|(1<<(p-1))][j]+f[i&1][ss][j])%mod;
                }
            }
    }
    int ans=0;
    for(int i=m;i<=n;++i)ans=(1ll*ans+f[n&1][(1<<n)-1][i])%mod;
    write(ans);
    return 0;
}