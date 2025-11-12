#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct node
{
    int x;
    int y;
    int w;
}a[N];
int b[15][N];
int fa[N];
int f(int x)
{
    return x == fa[x]?x:fa[x] = f(fa[x]);
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i<=n;++i)
    {
        fa[i] = i;
    }
    for(int i = 1;i<=m;++i)
    {
        cin >> a[i].x >> a[i].y >> a[i].w;
        /*int maxx = 0;
        for(int j = 1;j<=k;++j)
        {
            maxx = max(maxx,b[j][0]+b[j][a[i].x]+b[j][a[i].y]);
        }
        a[i].w = max(a[i].w,maxx);*/
    }
    for(int i = 1;i<=k;++i)
    {
        cin >> b[i][0];
        for(int j = 1;j<=n;++j)
        {
            cin >> b[i][j];
        }
    }
    sort(a+1,a+m+1,cmp);
    long long sum = 0;
    for(int i = 1;i<=m;++i)
    {
        int x = f(a[i].x),y = f(a[i].y);
        if(x!=y)
        {
            //cout << a[i].x << " " << a[i].y << " " << maxx << "\n";
            fa[x] = y;
            sum+=a[i].w;
        }
    }
    cout << sum;
    return 0;
}