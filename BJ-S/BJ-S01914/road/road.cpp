#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w;
long long c[10];
long long sum;
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> u >> v >> w;
    }
    for(int j = 1;j <= k;j++)
    {
        for(int i = 0;i <= n;i++)
        {
            long long x;
            cin >> x;
            c[j] += x;
            cout <<c[j]<<" ";
        }
    }
    sort(c + 1,c + k + 1);
    cout << c[1];
    return 0;
}
