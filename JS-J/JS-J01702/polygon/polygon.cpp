#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=5005,mod=998244353;
int n;
int ans=0;
int a[N],c[N],cnt=0,dp[N][N],C[N][N];
map<int,int> mp;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
int qpow(int a,int b){
    int ans=1%mod;
    for(;b;b>>=1){
        if(b&1)  ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
void init(){
    C[0][0]=1;
    for(int i=1;i<=5000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)  C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        mp[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(auto v:mp){
        int mx=v.fi;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=mx)  continue;
            c[++cnt]=a[i];
        }
        if(cnt+v.se<3)  continue;
        for(int i=0;i<=cnt;i++){
            for(int j=0;j<=mx;j++)  dp[i][j]=0;
        }
        dp[0][0]=1;
        for(int i=1;i<=cnt;i++){
            for(int j=0;j<=mx;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(j-a[i]>=0)  dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
            }
        }
        int  tmp=0;
        for(int i=0;i<=mx;i++)  tmp=(tmp+dp[cnt][i])%mod;
        ans=(ans+(qpow(2,cnt)-tmp+mod)%mod*C[v.se][1]%mod)%mod;
        if(v.se>=2)  ans=(ans+(qpow(2,cnt)-1+mod)%mod*C[v.se][2]%mod)%mod;
        for(int i=3;i<=v.se;i++)  ans=(ans+qpow(2,cnt)*C[v.se][i]%mod)%mod;
    }
    printf("%lld",ans);
    return 0;
}
