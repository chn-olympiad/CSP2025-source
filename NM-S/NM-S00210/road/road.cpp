#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1000005]
int main()
{
    freopen("roard.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n>> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int a,b;
        cin >> a >> b >> w[i];
    }
    sort(w + 1,w + n +1);
    long long ans = 0;
    for (int i = 1;i < n;i++)
        ans += w[i];
    cout << ans;
    return 0;
}
