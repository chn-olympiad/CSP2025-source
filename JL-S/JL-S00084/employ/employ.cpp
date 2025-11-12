#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int m,n,c[N];
char s[N];
namespace Sub1{
    bool vis[N];
    int a[N],ans=0;
    void check(){
        int lst=0;
        for(int i=1;i<=n;i++){
            if((i-1-lst)<c[a[i]]&&s[i]=='1') lst++;
        }
        if(lst>=m) ans++;
    }
    void dfs(int u){
        if(u==n+1){
            check();
            return;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                a[u]=i;
                vis[i]=1;
                dfs(u+1);
                vis[i]=0;
            }
        }
    }
    void Solve(){
        for(int i=1;i<=n;i++) vis[i]=0;
        dfs(1);
        cout<<ans<<"\n";
        exit(0);
    }
}
void Add(int &x,int y){
    x+=y;
    x%=mod;
}
namespace Sub2{
    int dp[262150][22];
    vector<int> State[22];
    void Solve(){
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int sta=0;sta<(1<<n);sta++){
            State[__builtin_popcountll(sta)].push_back(sta);
        }
        for(int i=0;i<n;i++){
            for(int sta:State[i]){
                for(int j=0;j<=i;j++){
                    for(int cur=1;cur<=n;cur++){
                        if(sta>>(cur-1)&1) continue;
                        if(j<c[cur]&&s[i+1]=='1') Add(dp[sta|(1<<(cur-1))][j],dp[sta][j]);
                        else Add(dp[sta|(1<<(cur-1))][j+1],dp[sta][j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n-m;i++) Add(ans,dp[(1<<n)-1][i]);
        cout<<ans<<"\n";
        exit(0);
    }
}
namespace Sub3{
    void Solve(){
        for(int i=1;i<=n;i++) if(s[i]!='1') cout<<"0\n",exit(0);
        for(int i=1;i<=n;i++) if(c[i]==0) cout<<"0\n",exit(0);
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans<<"\n";
        exit(0);
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=10) Sub1::Solve();
    if(n<=18) Sub2::Solve();
    if(m==n) Sub3::Solve();
    return 0;
}