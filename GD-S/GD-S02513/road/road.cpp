#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 15,M = 1e6 + 5;
int n,m,k,cnt,f[N],c[10];
ll ans,sum;
struct Edge{int x,y,z;} e[M],g[N * 11];
int find(int x){return (f[x] == x ? x : f[x] = find(f[x]));}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    sort(e + 1,e + m + 1,[&](Edge x,Edge y){return x.z < y.z;});
    iota(f + 1,f + n + 1,1);
    for(int i = 1;cnt < n - 1;i++)
    {
        int fx = find(e[i].x),fy = find(e[i].y);
        if(fx != fy) ans += e[i].z,g[++cnt] = e[i],f[fy] = fx;
    }
    for(int i = 0;i < k;i++)
    {
        scanf("%d",&c[i]);
        for(int j = 1,v;j <= n;j++)
        {
            scanf("%d",&v);
            g[++cnt] = (Edge){n + 1 + i,j,v};
        }
    }
    sort(g + 1,g + cnt + 1,[&](Edge x,Edge y){return x.z < y.z;});
    for(int i = 1,w;i < (1 << k);i++)
    {
        sum = 0,w = n - 1;
        for(int j = 0;j < k;j++) if((i >> j) & 1) sum += c[j],w++;
        iota(f + 1,f + n + k + 1,1);
        for(int j = 1,c = 0;c < w && sum < ans;j++)
        {
            if(g[j].x > n && !((i >> (g[j].x - n - 1)) & 1)) continue;
            int fx = find(g[j].x),fy = find(g[j].y);
            if(fx != fy) sum += g[j].z,c++,f[fy] = fx;
        }
        if(sum < ans) ans = sum;
    }
    printf("%lld\n",ans);
    return 0;
}