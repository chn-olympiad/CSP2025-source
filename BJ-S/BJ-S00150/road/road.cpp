#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
struct road
{
    ll u;
    ll v;
    ll w;
}r[10000000];
int main()
{
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    ll tmp = 0,sum = 1000000000000000,sumtmp = 0;
    cin >> n >> m >> k;
    for(int i = 1;i<=m;i++)
    {
        cin >> r[i].u >> r[i].v >> r[i].w;
    }
    for(int i = 1;i<=k;i++)
    {
        sumtmp = 0;
        for(int i = 1;i<=n+1;i++)
        {
            cin >> tmp;
            sumtmp+=tmp;
        }
        sum = min(sum,sumtmp);
    }
    cout << sum;
    return 0;
}
