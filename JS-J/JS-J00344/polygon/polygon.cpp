#include <iostream>
#include <algorithm>
using namespace std;

int a[5010];
int f[5010];
int mod = 998244353;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    long long m = 1;
    for(int i = 1;i <= n;i++)
    {
        m *= 2;
    }
    for(int i = 1;i < m;i++)
    {
        f[1] ++;
        int sum = 0;
        int maxn = -1;
        for(int j = 1;j <= n;j++)
        {
            if(f[j] > 1)
            {
                f[j + 1]++;
                f[j] = 0;
            }
            if(f[j]) sum += a[j];
            if(maxn < a[j] && f[j] == 1) maxn = a[j];
        }
        if(sum > maxn * 2)
        {
            cnt++;
            cnt %= mod;
        }
    }
    cout << cnt;
    return 0;
}
