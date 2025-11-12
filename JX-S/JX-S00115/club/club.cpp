#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long read()
{
    char ch;
    int num = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') num = num * 10 + (ch - '0'), ch = getchar();
    return num;
}
const int MAXN = 1e5 + 5;
struct node
{
    int c[5];
    int x[2], y[2], z[2];
    int id;
} a[MAXN];


int t, n, maxn;
bool vis[MAXN];

void dfs(int s, int ans, int p1, int p2, int p3)
{
    if(s > n){
        maxn = max(maxn, ans);
        //cout << p[1] << " " << p[2] << " " << p[3] << " " << ans << endl;
        return;
    }
        if(p1 < n/2) dfs(s + 1, ans + a[s].c[1], p1 + 1, p2, p3);
        //cout << a[i].id << " " << i << endl;
        if(p2 < n/2) dfs(s + 1, ans + a[s].c[2], p1, p2 + 1, p3);
        if(p3 < n/2) dfs(s + 1, ans + a[s].c[3], p1, p2, p3 + 1);
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t = read();
    while(t--)
    {
        memset(vis, false, sizeof(vis));
        maxn = 0;
        int ans = 0;
        n = read();
        for(int i = 1; i <= n; i++)
        {
            a[i].c[1] = read(),a[i].c[2] = read(),a[i].c[3] = read();
            a[i].id = i;
        }
        int p[4] = {0, 0, 0, 0};
        dfs(1, 0, 0, 0, 0);
        cout << maxn << '\n';
    }
    return 0;
}
