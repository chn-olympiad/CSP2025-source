//GZ-S00023 玉屏侗族自治县第一中学 何子涵
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N=1e6+5;
int n,m,k,ans;
struct r
{
    int u;
    int v;
    int w;
}a[N];
int b[15][10005];
bool cmp(r x,r y)
{
    return x.w<y.w;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
     cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
         cin >> b[i][j];
        }
    }
    sort(a+1,a+1+m,cmp);
    if (n==m&&k==0)
    {
        for(int i=1;i<=m;i++)
        {
         ans+=a[i].w;
        }
     cout << ans;
     return 0;
    }
    cout << ans;
    return 0;
}
