#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505,MOD=998244353;
int n,m,ans=1;
int c[MAXN],vis[MAXN];
string s;
void dfs(int x,int cnt){
    if(n-cnt<m) return ;
    if(x==n+1){
        if(n-cnt>=m) ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1,dfs(x+1,cnt+(cnt>=c[i]||!(s[x-1]-'0'))),vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    int flag=1,flag2=0;
    for(int i=1;i<=n;i++) flag=min(flag,(int)(s[i-1]-'0'));
    for(int i=1;i<=n;i++) cin>>c[i],flag2+=(c[i]==0);
    if(n<=18){
        ans=0;
        dfs(1,0);
        cout<<ans<<'\n';
        return 0;
    }
    if(n-flag2<m){
        cout<<0;
        return 0;
    }
    if(flag){
        for(int i=1;i<=n;i++) ans=ans*i%MOD;
        cout<<ans<<'\n';
        return 0;
    }
}