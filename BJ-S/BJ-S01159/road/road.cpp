#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i = l;i<=r;i++)
#define LL long long
const int N = 1e4+5,M = 1e6+5,K = 15;
int n,m,k,f[N+K],a[K][N],c[N];
struct Edge
{
    int x,y,z;
}e[M<<1];
bool cmp(Edge a,Edge b)
{
    return a.z < b.z;
}
int find(int x)
{
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    bool flag = 1;
    for(int i = 1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]) flag = 0;
        for(int j = 1;j<=n;j++) cin>>a[i][j];
    }
    if(!k)
    {
        LL ans = 0;
        for(int i = 1;i<=n;i++) f[i] = i;
        sort(e+1,e+m+1,cmp);
        for(int i = 1;i<=m;i++)
        {
            int x = find(e[i].x),y = find(e[i].y),z = e[i].z;
            if(x != y)
            {
                f[x] = y;
                ans += z;
            }
        }
        cout << ans << '\n';
    }
    else if(flag)
    {
        for(int i = 1;i<=n+k;i++) f[i] = i;
        for(int i = 1;i<=k;i++)
            for(int j = 1;j<=n;j++)
                e[++m] = {i+n,j,a[i][j]};
        LL ans = 0;
        sort(e+1,e+m+1,cmp);
        for(int i = 1;i<=m;i++)
        {
            int x = find(e[i].x),y = find(e[i].y),z = e[i].z;
            if(x != y)
            {
                f[x] = y;
                ans += z;
            }
        }
        cout << ans << '\n';
        return 0;
    }
    //k<=5
    else
    {
        LL ans = 1e18;
        for(int s = 0;s<(1<<k);s++)
        {
            for(int i = 1;i<=n+k;i++) f[i] = i;
            LL sum = 0;
            int cur = m;
            for(int i = 0;i<k;i++)
            {
                if(!(s>>i&1)) continue;
                sum += c[i+1];
                for(int j = 1;j<=n;j++)
                    e[++cur] = {i+n+1,j,a[i+1][j]};
            }
            sort(e+1,e+cur+1,cmp);
            for(int i = 1;i<=cur;i++)
            {
                int x = find(e[i].x),y = find(e[i].y),z = e[i].z;
                if(x != y)
                {
                    f[x] = y;
                    sum += z;
                }
            }
            ans = min(ans,sum);
        }
        cout << ans << '\n';
    }
    return 0;
}