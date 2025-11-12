#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+50;
const int mod=998244353;

template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
ll n,s[N],m,ans=0;
ll dp[N],dp2[N];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read<ll>();
    for(ll i=1;i<=n;i++){
        s[i]=read<ll>();
    }
    sort(s+1,s+n+1);
    m=s[n];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=m+1;j++){
            dp2[j]=(dp2[j]+dp[j])%mod;
            dp2[min(m+1,j+s[i])]=(dp2[min(m+1,j+s[i])]+dp[j])%mod;
        }
        for(ll j=s[i]+1;j<=m+1;j++){
            ans=(ans+dp[j])%mod;
        }
        for(ll j=0;j<=m+1;j++){
            dp[j]=dp2[j];
            dp2[j]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
