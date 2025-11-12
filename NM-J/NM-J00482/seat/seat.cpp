#include"bits/stdc++.h"
using namespace std;

const int N = 10,M = 10;
int a[N + 10][M + 10],v[N * M + 10],n,m,c,r,sh;
int dx[] = {0,1,-1,0},dy[] = {0,0,0,1};

void dfs(int x,int y,int k)
{
    a[x][y] = v[k];
    if(v[k] == sh)
    {
        c = y;r = x;
    }

    int tx,ty;
    for(int i = 1;i <= 3;i++)
    {
        tx = x + dx[i];
        ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == 0)
        {
            dfs(tx,ty,k - 1);
        }
    }
    return;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    memset(a,0,sizeof(a));
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> v[i];
    }
    sh = v[1];
    sort(v + 1,v + 1 + n * m);
    dfs(1,1,n * m);
    cout << c << " " << r;
    return 0;
}
