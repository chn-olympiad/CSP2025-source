#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
struct dat
{
    int u,v,w;
}a[1000005];
bool cmp (dat x, dat y)
{
    return x.w < y.w;
}
int f[1000005];
int find(int x)
{
    if(f[x]!=x) f[x] = find(f[x]);
    return f[x];
}
void merge(int x,int y)
{
    f[find(x)] = find(y);
}
int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int ans = 0;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i = 1; i <= k;i++)
    {
        int trash;
        cin >> trash;
    }
    sort(a+1,a+m+1,cmp);
    for(int i = 1;i <= m;i++)f[i] = i;
    for(int i = 1;i <= m;i++)
    {
        if(find(a[i].u)!= find(a[i].v))
        {
            merge(a[i].u,a[i].v);
            ans += a[i].w;
        }
    }
    cout << ans;
    return 0;
}
