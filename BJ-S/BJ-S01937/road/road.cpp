#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 2e6 + 5;
int n,m,k;
int t,f[maxn],flag[15];
ll ans;
ll b[maxn];
struct N
{
    int u,v;
    ll w,num;
}a[maxm];
int cmp(N x,N y)
{
    return x.w < y.w;
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
    cin >> n >> m >> k;
    while(m--)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        a[++t].u = u,a[t].v = v,a[t].w = w;
    }
    for(int i = 1;i <= k;i++)
    {
        ll x;
        cin >> x;
        for(int j = 1;j <= n;j++)
        {
            cin >> b[j];
            for(int k = 1;k < j;k++)
            {
                a[++t].u = k,a[t].v = j,a[t].w = b[k] + b[j],a[t].num = x;
                //cout << a[t].u << " " << a[t].v << " " << a[t].w << endl;
            }
        }
    }
    sort(a + 1,a + 1 + t,cmp);
    //for(int i = 1;i <= t;i++)
    //{
    //    cout << a[i].u << " " << a[i].v << " " << a[i].w + a[i].num << endl;
    //}
    //cout << endl;
    for(int i = 1;i <= n;i++) f[i] = i;
    for(int i = 1;i <= t;i++)
    {
        if(a[i].num != 0)
            if(a[i].w + a[i].num > a[i+1].w + a[i+1].num)
                swap(a[i],a[i+1]);
        int u = a[i].u,v = a[i].v;
        if(find(u) == find(v)) continue;
        if(a[i].num != 0 && !flag[a[i].num]) ans += a[i].num,flag[a[i].num]++;
        f[find(u)] = find(v);
        //cout << u << " " << v << " " << a[i].w << endl;
        ans += a[i].w;
    }
    cout << ans;
    return 0;
}
