#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int MAXN=5e2+10;
int n,m,cnt;
string s;
int c[MAXN],ans,b[MAXN],vis[MAXN];
int fac[MAXN],inv[MAXN],t[MAXN];
void dfs(int now){
    if(now==n+1){
        int bad=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') bad++;
            else if(c[b[i]]<=bad) ++bad;
        }
        if(n-bad>=m)++ans;return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;b[now]=i;dfs(now+1);vis[i]=0;
    }
}
void dfs1(int now){
    if(now<=cnt){
        
    }
}
int ksm(int a,int b){
    int num=1;
    while(b){
        if(b&1) (num*=a)%=mod;
        (a*=a)%=mod;b>>=1;
    }return num;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>m;cin>>s;s=" "+s;fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=ksm(fac[n],mod-2);
    for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    if(n<=10) {
        dfs(1);cout<<ans;
    }
    return 0;
}