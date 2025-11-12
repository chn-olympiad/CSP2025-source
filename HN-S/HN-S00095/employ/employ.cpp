#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
// char buf[1<<23],*p1=buf,*p2=buf;
int read(){char c=getchar();int p=0,flg=1;while(c<'0'||c>'9'){if(c=='-') flg=-1;c=getchar();}while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}return p*flg;}
int n,m,a[510],dp[1<<18][20],popc[1<<18];string s;
void sub1(){
    dp[0][0]=1;
    for(int S=1;S<(1<<n);S++){
        popc[S]=popc[S^(S&-S)]+1;
        for(int i=0;i<popc[S];i++) for(int j=1;j<=n;j++) if(S>>j-1&1){
            (dp[S][i+(s[popc[S]]=='1'&&popc[S]-1-i<a[j])]+=dp[S^(1<<j-1)][i])%=mod;
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++) (ans+=dp[(1<<n)-1][i])%=mod;
    cout<<ans;
}
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    n=read();m=read();cin>>s;s=" "+s;for(int i=1;i<=n;i++) a[i]=read();
    if(n<=18) sub1();
    return 0;
}