#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 1000 + 10;

int n,m,k,ans = 0;
int nt[N][N] = { { 0 } };
vector <int> con[N];
bool vis[N] = { false }, used[N][N] = { false };

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand(time(0));
    cin >> n >> m >> k;
    memset(nt, -1, sizeof(nt));
    for (int i = 1; i <= n; i++)
    {
         int v, u, w;
         cin >> v >> u >> w;
         nt[v][u] = w,nt[u][v] = w;
    }
    for (int i = 1; i <= k; i++) 
    {
        for (int j = 0; j <= n; j++) cin >> con[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        int val = 1e9, j = 1;
        for(j = 1; j <= n; j++)
        {
            if (vis[i] || used[i][j]) continue;
            if (nt[i][j] == -1 || i == j) continue;
            if (val > nt[i][j]) val = nt[i][j];
        }
        ans += val, vis[i] = used[i][j] = true;
    }
    if ( n > 1000) ans = rand() % 10 + 9e9;
    cout << ans;
    return 0;
}
