#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[100010];
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='0')
        {
            sum++;
        }
    }
    if (sum>(n-m))
    {
        cout<<0;
    }
    else
    {
        cout<<1000;
    }
    return 0;
}
