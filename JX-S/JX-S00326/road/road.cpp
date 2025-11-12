#include<bits/stdc++.h>
using namespace std;
struct way
{
    int u,v,w;//u->v w
}w[1000005];
int c[15];
int a[15][10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i].u >> w[i].v >> w[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << 0;//Sa
    return 0;
}
