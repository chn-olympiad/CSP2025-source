#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m;string s;
int c[505],a[505],pos[15];
int fac[505];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0]=1;
    for(int i=1;i<=500;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    cin>>n>>m;
    cin>>s;s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;pos[i]=i;
    }
    if(n<=10){
        int ans=0;
        do{
            int nw=0;
            for(int i=1;i<=n;i++){
                if(a[pos[i]]<=nw||s[i]=='0'){
                    nw++;
                }
            }
            if(n-nw>=m){
                ans++;
            }
        }
        while(next_permutation(pos+1,pos+n+1));
        cout<<ans;
        return 0;
    }
    if(m==n){
        int flag=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0')flag=1;
        }
        for(int i=1;i<=n;i++)if(a[i]==0)flag=1;
        if(flag){
            cout<<0;
            return 0;
        }
        else{
            cout<<fac[n];
            return 0;
        }
    }
    //no time bruh
    if(m==1){
        for(int i=1;i<=n;i++)c[i]+=c[i-1];
        int res=1,ss=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1')res=res*(c[i-1]-ss)%mod;
            if(s[i]=='1')ss++;
        }
        res=res*fac[n-ss]%mod;
        cout<<(fac[n]-res+mod)%mod;
    }
    return 0;
    /*
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int u=0;u<i;u++){
            for(int j=1;j<=n;j++){
                dp[i][j]+=1ll*dp[u][j-1]*aa(a[j-1]-(u-(j-1)),i-u-1)%mod;
                dp[i][j]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=m;i<=m;i++){
        ans+=1ll*dp[n][i]*fac[n-i]%mod;//shengxiadexiatian
    }
    cout<<ans;
    return 0;
    */
}
