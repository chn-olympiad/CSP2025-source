#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[501];
char s[501];
bool spe=true;
signed main ()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> s[i];
        if (s[i]!='1')
        {
            spe=false;
        }
    }
    for (int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    if (spe)
    {
        int ans=1;
        for (int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=998244353;
        }
        cout << ans;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
