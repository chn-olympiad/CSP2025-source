#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,res,c[505],d[505];
char s[505];
bool b[505],vis[505];
void dfs(int cnt){
    if(cnt==n+1){
        int js=0,ans=0;
        for(int i=1;i<=n;i++){
            if(js>=d[i]) js++;
            else if(b[i]==0) js++;
            else ans++;
            if(i==n&&ans>=m) res=(res+1)%mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            d[cnt]=c[i];
            dfs(cnt+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
        if(s[i-1]=='1') b[i]=1;
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    dfs(1);
    printf("%lld\n",res%mod);
    return 0;
}

