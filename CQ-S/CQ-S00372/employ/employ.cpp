#include<iostream>
constexpr int maxn=500+5,mod=998244353;
int n,m,c[maxn],vis[maxn],ans;
bool s[maxn];
void dfs(int x){
    if(x==n+1){
        int cc=0;
        for(int i=1;i<=n;++i) if(!s[i]||cc>=c[vis[i]]) ++cc;
        if(n-cc>=m) ++ans;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=x;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    std::freopen("employ.in","r",stdin);
    std::freopen("employ.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>m;
    std::cin.get();
    for(int i=1;i<=n;++i) s[i]=std::cin.get()=='1';
    for(int i=1;i<=n;++i) std::cin>>c[i];
    dfs(1);
    std::cout<<ans;
    return 0;
}