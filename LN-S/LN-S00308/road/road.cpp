#include <bits/stdc++.h>
using namespace std;
#define inf 1e9+7
#define int long long

int n,m,k;
int go[40000010],nxt[40000010],adj[10000010],val[40000010],ecnt,dp[40000010],cnt;

void add_(int u,int v,int w) {go[++ecnt]=v,nxt[ecnt]=adj[u],adj[u]=ecnt,val[ecnt]=w;}

void dfs(int x,int fa) {
    if (x==fa) return ;
    dp[x]=min(dp[x],dp[fa]+val[x]);
    // cout<<x<<" "<<fa<<" "<<dp[x]<<" "<<val[x]<<" "<<dp[fa]<<" "<<dp[fa]+val[x]<<" "<<"\n";
    for (int i=adj[x];i;i=nxt[i]) {
        if (go[i]==fa) return ;
        if (cnt>n*2) return ;
        cnt++;
        dfs(go[i],x); 
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    memset(dp,inf,sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        add_(u,v,w);
        add_(v,u,w);
    }
    for (int i=1;i<=k;i++) {
        int c,a;
        cin>>c;
        for (int j=1;j<=n;j++) {
            cin>>a;
            for (int t=1;t<=n;t++) {
                if (t==j) continue;
                add_(t,j,a+c);
                add_(j,t,a+c);
            }
        }
    }
    dfs(1,0);
    cout<<dp[n]<<"\n";
    return 0;
}