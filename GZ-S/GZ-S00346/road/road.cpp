#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+10;

int n,m,k;
vector<pair<int,int> > g[N];
int e[N];
ll tot = 0x3f3f3f3f3f3f3f3f,cost = 0;
int f[N];

int search(int x)
{
    if(x != f[x]) f[x] = search(f[x]);
    return f[x];
}

void init()
{
    for(int i = 0 ; i <= n + k ; i++) f[i] = i;
}

bool check()
{
    for(int i = 1; i <= n - 1 ; i++)
    {
        if(search(i) != search(i+1)) return 0;
    }
    return 1;
}

void dfs(int x)
{
    if(check()) tot = min(tot,cost);
    for(auto edge : g[x])
    {
        if(search(x) != search(edge.first))
        {
            int tmp2 = f[search(edge.first)];
            if(edge.first > n)
            {
                f[search(edge.first)] = f[search(x)];
                cost += e[edge.first] + edge.second;
                dfs(edge.first);
                cost -= (e[edge.first] + edge.second);
                f[edge.first] = tmp2;
            }else{
                f[search(edge.first)] = f[search(x)];
                cost += edge.second;
            }
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        if(search(i) != search(x))
            dfs(i);
        }
    }
     if(check()) tot = min(tot,cost);
    return ;
}

int main()
{
     freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i = n+1; i <= n+k ; i++)
    {
        cin >> e[i];
        for(int j = 1; j <= n ; j++)
        {
            int v;
            cin >> v;
            g[j].push_back({i,v});
            g[i].push_back({j,v});
        }
    }

    for(int i = 1; i <= n ; i++)
    {
        init();
        cost = 0;
        dfs(i);
    }
    cout << tot << '\n';

    return 0;
}
