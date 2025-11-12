#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans,s[510],c[510],vis[510];
char tmp[510];
void dfs(long long now,long long ly){
    if(now==n+1){
        if(ly>=m) ans++,ans%=mod;
        return ;
    }
    for(long long i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            if(!s[now] || c[i]<=now-ly-1) dfs(now+1,ly);
            else dfs(now+1,ly+1);
            vis[i]=0;
        }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,tmp+1);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&c[i]),s[i]=tmp[i]-'0';
    dfs(1,0);
    return !printf("%lld",ans);
}