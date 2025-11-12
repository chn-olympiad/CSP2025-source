#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN = 1e4+15;
const int MAXM = 1e7+5;
struct p
{
    int u,v,w;
} a[MAXM],d[MAXM];
int fa[MAXN],c[MAXN];
int b[11][MAXN];
bool f[MAXN];

bool cmp(p x,p y){return x.w < y.w;}

int getfa(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = getfa(fa[x]);
}

void merge(int x,int y)
{
    x = getfa(x);
    y = getfa(y);
    fa[x] = y;
}

long long ans = 1e18;
void dfs(int x)
{
    if(x > k)
    {
        int cnt = m;
        for(int i = 1;i <= m;i++) a[i] = d[i];
        long long sum = 0;
        for(int i = 1;i <= k+n;i++) fa[i] = i;
        for(int i = 1;i <= k;i++)
        {
            //cout << f[i] << endl;
            //assert(f[i] == 0);
            if(!f[i]) continue;
            sum += c[i];
            for(int j = 1;j <= n;j++)
            {
                ++cnt;
                a[cnt].u = n+i;
                //cout << "???" << n+i << endl;
                a[cnt].v = j;
                a[cnt].w = b[i][j];
            }
        }
        if(sum >= ans) return;
        //cout << endl;
        sort(a+1,a+cnt+1,cmp);
        for(int i = 1;i <= cnt;i++)
        {
            //cout << a[i].u << " " << a[i].v << " " << a[i].w << endl;
            int u = getfa(a[i].u);
            int v = getfa(a[i].v);
            if(u == v) continue;
            merge(u,v);
            sum += a[i].w;
        }
        //cout << sum << endl;
        //cout << "----------------" << endl;
        ans = min(ans,sum);
        return;
    }
    f[x] = 0;
    dfs(x+1);
    f[x] = 1;
    dfs(x+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    bool flag = 1;
    for(int i = 1;i <= m;i++) cin >> d[i].u >> d[i].v >> d[i].w;
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        if(c[i] != 0) flag = 0;
        for(int j = 1;j <= n;j++)
        {
            cin >> b[i][j];
        }
    }
    //cout << flag << endl;
    if(flag)
    {
        int cnt = m;
        ans = 0;
        for(int i = 1;i <= n+k;i++) fa[i] = i;
        for(int i = 1;i <= k;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                ++cnt;
                d[cnt].u = n+i;
                d[cnt].v = j;
                d[cnt].w = b[i][j];
            }
        }
        sort(d+1,d+cnt+1,cmp);
        for(int i = 1;i <= cnt;i++)
        {
            //cout << d[i].u << " " << d[i].v << " " << d[i].w << endl;
            int u = getfa(d[i].u);
            int v = getfa(d[i].v);
            if(u == v) continue;
            merge(u,v);
            ans += d[i].w;
        }
        cout << ans;
    }
    else
    {
        dfs(1);
        cout << ans;
    }
    return 0;
}
