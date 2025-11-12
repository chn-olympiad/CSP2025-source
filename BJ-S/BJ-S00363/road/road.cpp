#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e4;
const int M = 1e6;

int n,m,k;
int w[N + 10];
int fa[N + 10];
struct node
{
    int st;
    int ed;
    int len;
    bool operator < (const node &x) const
    {
        return len < x.len;
    }
};
node edge[M + N * 10 * 10];

int findfa(int x)
{
    if(fa[x] == x) return x;
    fa[x] = findfa(fa[x]);
    return fa[x];
}

int check()
{
    sort(edge + 1,edge + 1 + m);
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= m; i++)
    {
        int x = edge[i].st;
        int y = edge[i].ed;
        int w = edge[i].len;
        if(findfa(x) == findfa(y)) continue;
        fa[findfa(x)] = findfa(y);
        sum += w;
        cnt++;
        if(cnt == n - 1) return sum;
    }
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 1; i <= m; i++)
        cin >> edge[i].st >> edge[i].ed >> edge[i].len;
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        for(int j = 1; j <= n; j++)
            cin >> w[j];
        for(int j = 1; j <= n; j++)
        {
            if(j == i) edge[++m] = {i,j,w[j]};
            else edge[++m] = {i,j,w[j] + w[i]};
        }
    }
    cout << check();
    return 0;
}
