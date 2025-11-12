#include<bits/stdc++.h>
#define int long long
//#define endl '\n'
using namespace std;

int n,m,k;
int c[1001][1001];
int ans = 1ll << 60;
int f[2001][3001];

struct Node
{
    int u,v,w;
    bool operator <(const Node &nd)const
    {
        return this -> w > nd.w;
    }
};

Node a[1000001];

int find(int u,int times)
{
    if(f[times][u] == u)
    {
        return u;
    }
    return f[times][u] = find(f[times][u],times);
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i = 1;i <= k;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0;i <= (1 << k) - 1;i++)
    {
        int sum = 0;
        priority_queue<Node> q;
        for(int j = 1;j <= m;j++)
        {
            q.push(a[j]);
        }
        int cnt = n;
        for(int j = 1;j <= k;j++)
        {
            if(((i >> (j - 1)) & 1) == 0)
            {
                continue;
            }
            sum += c[j][0];
            cnt++;
            for(int l = 1;l <= n;l++)
            {
                q.push({cnt,l,c[j][l]});
            }
        }
        for(int j = 1;j <= cnt;j++)
        {
            f[i][j] = j;
        }
        int tk = 0;
        while(!q.empty())
        {
            Node res = q.top();
            q.pop();
            int l = res.u;
            int r = res.v;
            int w = res.w;
            int u = find(l,i);
            int v = find(r,i);
            if(u != v)
            {
                tk++;
                sum += w;
                f[i][u] = v;
            }
            if(tk >= cnt)
            {
                break;
            }
        }
        ans = min(ans,sum);

    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
