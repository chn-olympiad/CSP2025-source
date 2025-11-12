#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[505],f[(1<<20)][20];
int ff[505],C[505][505],t[505],jie[505];
int main(){
    freopen("employ3.in","r",stdin);
    //freopen("employ.out","w",stdout);
    for(int i=0;i<=500;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    jie[0]=1;
    for(int i=1;i<=500;i++)jie[i]=1LL*jie[i-1]*i%mod;
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        int ans=0;
        f[0][0]=1;
        for(int S=1;S<(1<<n);S++){
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(S&(1<<i-1))
                    cnt++;
            for(int i=1;i<=n;i++){
                bool e=S&(1<<i-1);
                if(!e)continue;
                int T=S-(1<<i-1);
                for(int j=0;j<=n;j++){
                    if(s[cnt]=='0'||j>=c[i])
                        f[S][j+1]=(f[S][j+1]+f[T][j])%mod;
                    else
                        f[S][j]=(f[S][j]+f[T][j])%mod;
                }
            }
        }
        for(int i=1;i<m;i++)
            ans=(ans+f[(1<<n)-1][i])%mod;
        cout<<ans;
        return 0;
    }
    if(n==m){
        int fff=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='0'||c[i]==0)
                fff=1;
        cout<<1-fff;
        return 0;
    }
    int fff=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='0')
            fff=1;
    if(!fff){
        int now=1;
        for(int i=1;i<=n;i++)t[c[i]]++;
        ff[0]=jie[n];
        for(int i=0;i<=n;i++){
            now=1LL*now*t[i]%mod;
            ff[i+1]=1LL*C[n][i+1]*now%mod;
        }
        for(int i=0;i<=n;i++){
            ff[i]-=ff[i+1];
            ff[i]=(ff[i]+mod)%mod;
        }
        int ans=0;
        for(int i=0;i<m;i++)
            ans=(ans+ff[i])%mod;
        cout<<ans;
        return 0;
    }
}
