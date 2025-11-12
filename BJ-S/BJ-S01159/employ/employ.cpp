#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i = l;i<=r;i++)
#define LL long long
const int N = 10005,mod = 998244353;
int n,m,c[N],v[N],bits[N];
char s[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool flag = 1;
    for(int i = 0;i<n;i++)
    {
        cin>>s[i];
        if(s[i] == '0') flag = 0;
    }
    if(flag)
    {
        bool ff = 1;
        for(int i = 1;i<=n;i++) if(!c[i]) ff = 0;
        int ans = 1;
        for(int i = 1;i<=n;i++) ans = ans*i%mod;
        if(ff) cout << ans << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    // for(int i = 0;i<n;i++) cin>>c[i];
    // for(int i = 0;i<(1<<n);i++)
    // {
    //     int cnt = 0,tot = 0;
    //     for(int j = 0;j<n;j++)
    //     {
    //         if(i >> j & 1) bits[i]++,cnt++;
    //         if(!s[cnt] || tot >= c[j]) tot++;
    //     }
    //     v[i] = tot;
    // }
    // for(int i = 0;i<n;i++) f[0][i] = 1;
    // for(int i = 0;i<(1<<n);i++)
    // {
    //     for(int j = 0;j<n;j++)
    //     {
    //         if(i >> j & 1)
    //         {
    //             for(int k = 0;k<n;k++)
    //             {
    //                 if(k == j) continue;
    //                 if(i >> k & 1)
    //                 {
    //                     if(v[i^(1<<j)] >= c[j]) continue;
    //                     if(s[bits[i]]) f[i][j] += f[i^(1<<j)][k];
    //             }
    //         }
    //     }
    // }
    return 0;
}