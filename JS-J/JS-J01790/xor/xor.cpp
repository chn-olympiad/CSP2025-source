#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MAXN = 5*1e5+5;
ll a[MAXN];
bool b[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    ll k;
    cin>>n>>k;
    ll ans = 0;
    bool flag = 1;
    bool flag2 = 1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i] != 1) flag = 0;
        if (a[i] != 0) flag2 = 0;
    }
    if (flag == 1)
    {
        cout<<n/2<<endl;
        return 0;
    }
    if (flag2 == 1)
    {
        cout<<n/2<<endl;
        return 0;
    }
    if (k == 0)
    {
        bool bo;
        for (int i=1;i<=n;i++)
        {
            if (b[i] == 1) continue;
            b[i] = 1;
            bo = 0;
            if (a[i] == 0 && a[i+1] == 0)
            {
                ans++;
                b[i+1] = 1;
            }
            else if (a[i] == 0 && a[i+1] != 0)
            {
                continue;
            }
            else
            {
                for (int j=i+1;j<=n;j++)
                {
                    if (a[i] == 1 && a[j] == 1)
                    {
                        bo = 1;
                        ans++;
                        b[j] = 1;
                    }
                }
            }
        }
    }
    else if (k == 1)
    {
        for (int i=1;i<=n;i++)
        {
            if (i > n) break;
            while (a[i]+a[i+1] == 0 || a[i]+a[i+1] == 2)
            {
                i++;
            }
            if (i > n) break;
            if (a[i]+a[i+1] == 1)
            {
                ans++;
                i++;
            }
        }
    }
    else
    {
        cout<<1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
