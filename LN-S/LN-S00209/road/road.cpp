#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int na[N][N], se[N],ma[N][N],tre[N][N],ct[N];


long long dfs(int sh,int x)
{
    if(ct[x] == 0)
    {
        //cout<<sh<<" "<<x<<" " <<na[sh][x]<<"1\n";
        return na[sh][x];

    }
    else{
        long long ans = 0;
        for(int i  =1;i<=ct[x];i++)
        {
            ans+=dfs(x,tre[x][i]);
        }
        //cout<<sh<<" "<<x<<" " <<ans<<"2\n";
        return ans;
    }

}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    int u, v, w, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        if (na[u][v])
        {
            na[u][v] = min(w, na[u][v]);
            na[v][u] = na[u][v];
        }
        else
        {
            na[u][v] = w;
            na[v][u] = na[u][v];
        }
    }


    for (int h = 1; h <= n; h++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || i == h||h ==j||!na[h][i]||!na[j][i])
                    continue;
                if (na[h][i] > na[h][j] + na[i][j])
                {
                    na[h][i] = na[h][j] + na[i][j];
                    ma[h][i] = j;
                }
            }
        }
    }
    for(int i  =2;i<=n;i++)
    {
        if(ma[1][i])
        {
            tre[1][++ct[1]] = ma[1][i];
            tre[ma[1][i]][++ct[ma[1][i]]] = i;
        }
        else if(na[1][i])
        {
            tre[1][++ct[1]] = i;
        }
    }

    cout<<dfs(1,1);
    return 0;
}
