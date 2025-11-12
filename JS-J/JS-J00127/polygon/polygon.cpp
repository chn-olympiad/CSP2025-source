#include<bits/stdc++.h>
using namespace std;
int a[5005], v[5005], re[5005];
int n;
int record;
int df(int dep, int num, int xz, int cnt)
{
    re[dep] = num;
    v[num] = 1;
    if(dep == xz){
        sort(re + 1, re + dep + 1);
        record = re[dep];
        return cnt;
    }
    for(int i = 1; i <= n; i++)
    {
        if(v[i] == 0)
        {
            return df(dep + 1, i, xz, cnt + a[i]);
        }
        re[dep] = 0;
        v[num] = 0;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(df(0, j, i, 0) > 2 * record){
                ans++;
            }
        }

    }
    cout << ans % 998244353;
    return 0;
}
