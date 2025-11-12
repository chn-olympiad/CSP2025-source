# include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int head[N << 1],to[N << 1],nxt[N << 1],val[N],vis[N];
int dis[N];
int E;
const int inf = 1e9;
void add(int a,int b,int c)
{
    val[E] = c;
    to[E] = b;
    nxt[E] = head[a];
    head[a] = E++;
}
int n,m,k;
int ans;
void dfs(int u,int fa)
{
    // cout << u << endl;
    // for(int i = 1;i <= n;)
    for(int i = head[u];i != -1;i = nxt[i])
    {
        int v = to[i];
        if(v == fa) continue;
        if(!vis[v])
        {
            // cout << val[i] << endl;
            ans += val[i];
            // cout << ans << endl;
            vis[v] = 1;
            dfs(v,u);
        }
    }
}
int main (){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }       
    if(k == 0)
    {
        int minx = INT_MAX;
        for(int i = 1;i <= n;i++)
        {
            // cout << "debug : ";
            for(int j = 1;j <= n;j++) vis[j] = 0;
            ans = 0;
            vis[i] = 1;
            dfs(i,0);
            // cout << ans << endl;
            minx = min(minx,ans);
        }
        printf("%d\n",minx);
    }
    else   
    {
        printf("0\n");
    }
    return 0;
}