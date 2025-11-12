#include<bits/stdc++.h>
#define int long long
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin)),p1==p2?EOF:*p1++)
char buf[1<<23],*p1=buf,*p2=buf;
int read(){char c=getchar();int p=0,flg=1;while(c<'0'||c>'9'){if(c=='-') flg=-1;c=getchar();}while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}return p*flg;}
int n,m,k,fa[10010],f[10010][1<<5],g[1<<10],a[11],dp[10010][2],b[11][10010],mi[10010][1<<10],c[10010][1<<10];struct Edge{int u,v,w;}E[1000010];vector<array<int,2>>e[10010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    n=read();m=read();k=read();for(int i=1;i<=m;i++) E[i]={read(),read(),read()};for(int i=1;i<=k;i++){a[i]=read();for(int j=1;j<=n;j++) b[i][j]=read();}
    sort(E+1,E+1+m,[&](Edge x,Edge y){return x.w<y.w;});iota(fa+1,fa+1+n,1);
    int res=0;
    for(int i=1;i<=m;i++) if(find(E[i].u)^find(E[i].v)){
        fa[find(E[i].u)]=find(E[i].v);
        e[E[i].u].push_back({E[i].v,E[i].w});
        e[E[i].v].push_back({E[i].u,E[i].w});
        res+=E[i].w;
    }
    if(!k){cout<<res;return 0;}
    for(int i=1;i<=n;i++){
        mi[i][0]=1e18;
        for(int S=1;S<(1<<k);S++) mi[i][S]=min(mi[i][S^(S&-S)],b[__lg(S&-S)+1][i]),c[i][S]=c[i][S^(S&-S)]+b[__lg(S&-S)+1][i];
    }
    int ans=1e18;
    for(int S=0;S<(1<<k);S++){
        function<void(int,int)>dfs=[&](int u,int fa){
            if(u==1){
                dp[u][0]=dp[u][1]=0;
            }else{
                dp[u][0]=0;
                dp[u][1]=mi[u][S];
            }
            for(auto v:e[u]) if(v[0]^fa){
                dfs(v[0],u);
                int f0=1e18,f1=1e18;
                f0=min(f0,dp[u][0]+dp[v[0]][0]+v[1]);
                f0=min(f0,dp[u][0]+dp[v[0]][1]);
                f1=min(f1,dp[u][0]+dp[v[0]][1]+v[1]);
                f1=min(f1,dp[u][1]+dp[v[0]][0]+v[1]);
                f1=min(f1,dp[u][1]+dp[v[0]][1]);
                dp[u][0]=f0;
                dp[u][1]=f1;
            }
        };dfs(1,0);
        int sum=dp[1][1]+c[1][S];
        for(int i=1;i<=k;i++) if(S>>i-1&1) sum+=a[i];
        ans=min(ans,sum);
    }
    if(k>5){cout<<ans;return 0;}
    function<void(int,int)>dfs=[&](int u,int fa){
        for(int S=0;S<(1<<k);S++){
            for(int i=1;i<=k;i++) if(S>>i-1&1) f[u][S]+=b[i][u];
            g[S]=1e18;
        }
        for(auto v:e[u]) if(v[0]^fa){
            dfs(v[0],u);
            for(int S=0;S<(1<<k);S++) for(int T=0;T<(1<<k);T++){
                if(S&T) g[S|T]=min(g[S|T],f[u][S]+f[v[0]][T]);
                else g[S|T]=min(g[S|T],f[u][S]+f[v[0]][T]+v[1]);
            }
            for(int S=0;S<(1<<k);S++) f[u][S]=g[S],g[S]=1e18;
        }
    };dfs(1,0);
    for(int S=0;S<(1<<k);S++){
        int sum=f[1][S];
        for(int i=1;i<=k;i++) if(S>>i-1&1) sum+=a[i];
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}