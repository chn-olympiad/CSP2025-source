#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    sort(a+1,a+n+1);
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            for(int k = j+1; k <= n; k++)
            {
                if(a[i]+a[j] > a[k])
                {
                    ans++;
                }
            }
        }
    }
    cout << ans%p;
    return 0;
}
