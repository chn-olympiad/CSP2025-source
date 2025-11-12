#include<bits/stdc++.h>
#define reg register
// #define int long long
inline int read(){
    reg int x=0,k=1; reg char ch=getchar();
    while (ch<'0'||ch>'9') (ch=='-')&&(k=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*k; 
}
const int N=510,mod=998244353;
int n,m,c[N],f[1<<20|10][20],cnt[N];
char str[N];
signed main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    n=read(),m=read();
    scanf("%s",str+1);
    for (reg int i=1;i<=n;i++) c[i]=read();
    if (n<=18){
        f[0][0]=1;
        for (reg int s=0;s<1<<n;s++){
            reg int pc=__builtin_popcount(s);
            for (reg int i=0;i<=n;i++){
                for (reg int j=1;j<=n;j++) if (~s>>j-1&1){
                    reg int p=c[j]<=i||str[pc+1]=='0';
                    (f[s|1<<j-1][i+p]+=f[s][i])%=mod;
                }
            }
        }
        reg int ans=0;
        for (reg int i=0;i<=n;i++) if (n-i>=m) (ans+=f[(1<<n)-1][i])%=mod;
        printf("%d\n",ans);
        return 0;
    }
    if (n==m){
        for (reg int i=1;i<=n;i++){
            if (str[i]=='0') return puts("0"),0;
            if (c[i]==0) return puts("0"),0;
        }
        reg int ans=1;
        for (reg int i=1;i<=n;i++) ans=1ll*ans*i%mod;
        printf("%d\n",ans);
        return 0;
    }
    if (m==1){
        reg int ans2=1,S=0,ans=1;
        for (reg int i=1;i<=n;i++) S+=str[i]=='0';
        for (reg int i=1;i<=n;i++) cnt[c[i]]++;
        for (reg int i=n;i>=0;i--){
            for (reg int j=1;j<=cnt[i];j++){
                ans2=1ll*ans2*S%mod;
                S--;
            } 
            if (str[i]=='1') S++;
        } 
        for (reg int i=1;i<=n;i++) ans=1ll*ans*i%mod;
        printf("%d\n",(ans+mod-ans2)%mod);
    }
    return 0;
}